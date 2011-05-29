".vimrc��.exrc�ե�����Υ����Ȥ�"�ǻϤޤ롣
" Option Checkul http://www15.ocn.ne.jp/~tusr/vim/options_help.html 
" vim:tw=0:sw=4:ts=4:list:listchars=tab\:>-:foldmarker={{{,}}}:fdm=marker

"{{{ ��������
"����󥳥ޥ�ɤ�Ͽ�����
set history=50

"list��ɽ�������ʸ���Υե����ޥåȤ���ꤹ�롣
set listchars=tab:>-

"���ѥ��ڡ���������С֡��פ�ɽ������
highlight ZenkakuSpace cterm=underline ctermfg=lightblue guibg=white
match ZenkakuSpace /��/

"����ʸ���������ʤ��ԲĻ�ʸ����ɽ�����롣
set list

"�����syntax���դ��ǻ�Ŧ���롣�ѥ�᡼���˳�ĥ�һ���Ǥ��롣��:set syntax=html��
syntax on


"���䤹������ɽ������褦��Vim���طʿ��򶵤��롣dark��light������Ǥ��롣
set background=light

"�ֹ���ղä���
set number

"��������Ⱦ�ѱѻ�4ʸ��ʬ
set tabstop=4

"tabstop���Ѥ����˶����ޤ�뤳�Ȥˤ�ꡢ�����ܤ�tabstop���Ѥ���
set softtabstop=0

"���֤����Ϥ����ʸ�����֤������ʤ�(�����ͭ���ˤ���ȥ᡼���񤯻��ʤɤ�ͭ��)
set noexpandtab

"��ư����ǥ�Ȥ�Ⱦ�ѱѻ�4ʸ��ʸ
set shiftwidth=4

"�Ԥ�������Ĺ���ʤ�ȡ���������Ķ���ʤ��褦�˶���θ�ǲ��Ԥ���롣�ͤ� 0 �����ꤹ���̵���ˤʤ롣
set textwidth=0

"��ư�ǥ���ǥ�Ȥ�Ԥ�
set autoindent

"ʸ�������ɤ�EUC-JP
set encoding=euc-jp

"ü����ʸ�������ɤ�EUC-JP
set termencoding=euc-jp

"�ե������ʸ�������ɤ�EUC-JP
set fileencoding=euc-jp

"�ʲ���backup��Ϣ�Ԥ�¸�ߤ����$HOME/.backupdoc�ǥ��쥯�ȥ��<�ե�����̾>~�ΥХå����åפ�Ԥ���
set backup
set backupdir=$HOME/.backupdoc
set backupext=~
set backupskip=/tmp/*,$TMPDIR/*,$TMP/*,$TEMP/*
set backupdir=$HOME/.backupdoc

"�����������롣
set dictionary=$HOME/dev/vim/share/vim/phpman.dict

"���顼��������˲��̥ե�å����Ȥ�
set visualbell

"CTRL-_��'revins'���ץ�����ȥ��뤵���롣revins�ϵ����ϥ⡼��
set noallowrevins

" ����ɥ���ǽ���ѹ��κ�����
set undolevels=1024

"�ޤ��֤��������Ԥ���
set wrap

"����������Ƭ�������ǻߤޤ�ʤ��褦�ˤ��롣
set whichwrap=b

":s���ޥ�ɤ�'g'���ץ�����ǥե���ȤˤϤ��ʤ�
set nogdefault

"�Хå����ڡ�����ư�����ꡣ0,1,2������Ǥ��롣2�ξ��ˤ�set backspace=indent,eol,start��Ʊ��
set backspace=2

"autoindent��C����ץ���ߥ󥰸������ò�������ΤǤ���.(autoindent���⤳�����ͭ���ˤ���Ф褤)
set cindent

"���ޥ�ɥ饤���䴰����Ȥ����䴰�����ɽ�����롣(�� :e t<TAB>�Ȥ����t�ǻϤޤ�ե����뤬ɽ�������)
set wildmenu
"}}}

"{{{��������
"������̤�ϥ��饤��(��Ĵ)ɽ������
set hlsearch

"���󥯥��󥿥륵����(����ʸ�������Ϥ��Ƥ�����ʬ�ޤǤǸ�����Ԥ�)
set noincsearch

"������ե�����������ޤǸ��������顢�ե��������Ƭ�إ롼�פ��롣
set wrapscan

"����������ʸ���Ⱦ�ʸ���ζ��̤�Ԥ�ʤ�(default)
set noignorecase

"��ʸ����ʸ����ξ�����ޤޤ�Ƥ���Ȥ���ʸ����ʸ�������
set nosmartcase

"}}}

"{{{ɽ������
"���ߤΥ⡼�ɤ�ɽ������
set showmode

"�б����륫�å���ɽ������
set showmatch

"��å�������ܤ���ɽ������
set noterse

"̤��¸�ǽ�λ���褦�Ȥ�����ٹ𤹤�
set warn

"��ư���Υ�å�������ɽ�����ʤ��褦�ˤ��롣
"set shortmess+=I
"}}}

"{{{���ơ������饤������
"�����˹��ֹ������ղä���
set ruler

" ���ơ������Ԥ�ʸ�������ɤ���ԥ����ɤ�ɽ����statusline�����ꤵ����ruler��̵�뤵��롣
set statusline=%<%f\ %m%r%h%w%{'['.(&fenc!=''?&fenc:&enc).']['.&ff.']'}%=%l,%c%V%8P

"���ޥ�ɤ򥹥ơ������饤���ɽ�����롣
set showcmd

"���ơ������饤���ɽ�����륦����ɥ������ꤹ�롣
set laststatus=2
"}}}

"{{{�ޤ��������
"�ޤ���ߤ�Ԥ������ڤӽ�������ꤹ�롣
set foldmarker={{{,}}}

"�ޤ���ߤ�Ԥ�����Կ���������롣
set foldminlines=1

"�ޤ����ͥ��Ȥκ�����
set foldnestmax=20

"�Ĥ���줿�ޤ���ߤ򼨤��ƥ����Ȥ����뤿��˼¹Ԥ���륹����ץ�
set foldtext=foldtext()

"�������뤬��ư�����Ȥ��˼�ưŪ���ޤ���ߤ򳫤�
set foldopen=block,hor,mark,percent,quickfix,search,tag,undo
"}}}

"{{{���Τۤ�����

map! <F2> <C-x><C-k>

" ,h1��h1�����Ǥ��ιԤ��Ϥޤ��
imap ,h1 <h1>

"�����⡼�ɤ�_dt�����Ϥ���ȥ����ॹ����פ��Ѵ�����褦������
iab _dt <C-R>=strftime("%Y-%m-%d")<CR>

"�����⡼�ɤ�_sp�����Ϥ�������Ѷ���ʸ�������Ϥ����褦�����ꤹ��
"iab _sp

"F1�ǥإ�פ����Ϥ����褦������
map <F1> :help<Space>

"php�γ�ĥ�Ҥξ��˼����ɽ�����ޤ���
autocmd FileType php :set dictionary+=~/.vim/dict/php_functions.dict

"����ե��������Ѥ���������ѹ�
set complete+=k

"�ʲ���.test�Ȥ�����ĥ�Ҥ�.html��syntax���ѹ�����Ȥ�����Ǥ���
augroup filetypedetect
au BufRead,BufNewFile *.test setfiletype html
augroup END

"��ĥ�����������ǽ(�ʲ���)
"autocmd FileType python setlocal ts=4 sw=4 sta et sts ai

"}}}

"{{{ʸ�������ɼ�ưǧ������ 
if &encoding !=# 'utf-8'
      set encoding=japan
      set fileencoding=japan
endif
if has('iconv')
   let s:enc_euc = 'euc-jp'
   let s:enc_jis = 'iso-2022-jp'
      " iconv��eucJP-ms���б����Ƥ��뤫������å�
   if iconv("\x87\x64\x87\x6a", 'cp932', 'eucjp-ms') ==# "\xad\xc5\xad\xcb"
      let s:enc_euc = 'eucjp-ms'
      let s:enc_jis = 'iso-2022-jp-3'
      " iconv��JISX0213���б����Ƥ��뤫������å�
   elseif iconv("\x87\x64\x87\x6a", 'cp932', 'euc-jisx0213') ==# "\xad\xc5\xad\xcb"
      let s:enc_euc = 'euc-jisx0213'
      let s:enc_jis = 'iso-2022-jp-3'
   endif
   " fileencodings����
   if &encoding ==# 'utf-8'
      let s:fileencodings_default = &fileencodings
      let &fileencodings = s:enc_jis .','. s:enc_euc .',cp932'
      let &fileencodings = &fileencodings .','.  s:fileencodings_default
      unlet s:fileencodings_default
   else
      let &fileencodings = &fileencodings .','. s:enc_jis
      set fileencodings+=utf-8,ucs-2le,ucs-2
      if &encoding =~# '^\(euc-jp\|euc-jisx0213\|eucjp-ms\)$'
         set fileencodings+=cp932
         set fileencodings-=euc-jp
         set fileencodings-=euc-jisx0213
         set fileencodings-=eucjp-ms
         let &encoding = s:enc_euc
         let &fileencoding = s:enc_euc
      else
         let &fileencodings = &fileencodings .','.  s:enc_euc
      endif
   endif
"������ʬ
unlet s:enc_euc
unlet s:enc_jis
endif

"���ܸ��ޤޤʤ�����fileencoding��encoding��Ȥ��褦�ˤ���
if has('autocmd')
   function!  AU_ReCheck_FENC()
   if &fileencoding =~# 'iso-2022-jp' && search("[^\x01-\x7e]", 'n') == 0
      let &fileencoding=&encoding
   endif
   endfunction
   autocmd BufReadPost * call AU_ReCheck_FENC()
endif

"���ԥ����ɤμ�ưǧ��
set fileformats=unix,dos,mac
"���Ȥ�����ʸ�������äƤ⥫��������֤�����ʤ��褦�ˤ���
if exists('&ambiwidth')
   set ambiwidth=double
endif
"}}}
"
"colorscheme�����꤬�Ǥ���
colorscheme ron

" neocomplcache
let g:neocomplcache_enable_at_startup = 1 " ��ư����ͭ����

highlight Pmenu ctermbg=4
highlight PMenuSbar ctermbg=1
highlight PmenuSel ctermbg=4
