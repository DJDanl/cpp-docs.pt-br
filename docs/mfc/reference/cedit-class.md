---
title: Classe CEdit | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CEdit
- AFXWIN/CEdit
- AFXWIN/CEdit::CEdit
- AFXWIN/CEdit::CanUndo
- AFXWIN/CEdit::CharFromPos
- AFXWIN/CEdit::Clear
- AFXWIN/CEdit::Copy
- AFXWIN/CEdit::Create
- AFXWIN/CEdit::Cut
- AFXWIN/CEdit::EmptyUndoBuffer
- AFXWIN/CEdit::FmtLines
- AFXWIN/CEdit::GetCueBanner
- AFXWIN/CEdit::GetFirstVisibleLine
- AFXWIN/CEdit::GetHandle
- AFXWIN/CEdit::GetHighlight
- AFXWIN/CEdit::GetLimitText
- AFXWIN/CEdit::GetLine
- AFXWIN/CEdit::GetLineCount
- AFXWIN/CEdit::GetMargins
- AFXWIN/CEdit::GetModify
- AFXWIN/CEdit::GetPasswordChar
- AFXWIN/CEdit::GetRect
- AFXWIN/CEdit::GetSel
- AFXWIN/CEdit::HideBalloonTip
- AFXWIN/CEdit::LimitText
- AFXWIN/CEdit::LineFromChar
- AFXWIN/CEdit::LineIndex
- AFXWIN/CEdit::LineLength
- AFXWIN/CEdit::LineScroll
- AFXWIN/CEdit::Paste
- AFXWIN/CEdit::PosFromChar
- AFXWIN/CEdit::ReplaceSel
- AFXWIN/CEdit::SetCueBanner
- AFXWIN/CEdit::SetHandle
- AFXWIN/CEdit::SetHighlight
- AFXWIN/CEdit::SetLimitText
- AFXWIN/CEdit::SetMargins
- AFXWIN/CEdit::SetModify
- AFXWIN/CEdit::SetPasswordChar
- AFXWIN/CEdit::SetReadOnly
- AFXWIN/CEdit::SetRect
- AFXWIN/CEdit::SetRectNP
- AFXWIN/CEdit::SetSel
- AFXWIN/CEdit::SetTabStops
- AFXWIN/CEdit::ShowBalloonTip
- AFXWIN/CEdit::Undo
dev_langs:
- C++
helpviewer_keywords:
- separators, in multiline edit controls
- text editors
- controls [MFC], edit
- text editors, CEdit class
- edit controls, classes
- multiline edit control
- CEdit class
- line separators in multiline edit controls
- edit controls
ms.assetid: b1533c30-7f10-4663-88d3-8b7f2c9f7024
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 9c782e77b1fdb9026ee030238413955ba4d537e9
ms.lasthandoff: 02/25/2017

---
# <a name="cedit-class"></a>Classe CEdit
Fornece a funcionalidade de um controle de edição do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CEdit : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEdit::CEdit](#cedit)|Constrói uma `CEdit` objeto de controle.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEdit::CanUndo](#canundo)|Determina se uma operação de controle de edição pode ser desfeita.|  
|[CEdit::CharFromPos](#charfrompos)|Recupera os índices de linhas e de caracteres do caractere mais próximo em uma posição especificada.|  
|[CEdit::Clear](#clear)|Controle da seleção atual (se houver) na edição de exclusões (limpa).|  
|[CEdit::Copy](#copy)|Copia a seleção atual (se houver) no controle de edição para a área de transferência em **CF_TEXT** formato.|  
|[CEdit::Create](#create)|Cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.|  
|[CEdit::Cut](#cut)|A seleção atual (se houver) na edição de exclusões (cortes) controle e copia o texto excluído para a área de transferência em **CF_TEXT** formato.|  
|[CEdit::EmptyUndoBuffer](#emptyundobuffer)|Redefine o sinalizador desfazer uma edição (limpa) de controle.|  
|[CEdit::FmtLines](#fmtlines)|Define a inclusão de caracteres de quebra de linha suave ou desativar dentro de um controle de edição de várias linhas.|  
|[CEdit::GetCueBanner](#getcuebanner)|Recupera o texto que é exibido como a sinalização de texto ou a dica em um controle de edição quando o controle está vazio e não tem o foco.|  
|[CEdit::GetFirstVisibleLine](#getfirstvisibleline)|Determina a primeira linha visível em um controle de edição.|  
|[CEdit::GetHandle](#gethandle)|Recupera um identificador para a memória que está atualmente alocado para um controle de edição de várias linhas.|  
|[CEdit::GetHighlight](#gethighlight)|Obtém os índices de inicial e final de caracteres em um intervalo de texto é realçado no controle de edição atual.|  
|[CEdit::GetLimitText](#getlimittext)|Obtém a quantidade máxima de texto essa `CEdit` pode conter.|  
|[CEdit::GetLine](#getline)|Recupera uma linha de texto de um controle de edição.|  
|[CEdit::GetLineCount](#getlinecount)|Recupera o número de linhas em um controle de edição de várias linhas.|  
|[CEdit::GetMargins](#getmargins)|Obtém as margens esquerdas e direita para este `CEdit`.|  
|[CEdit::GetModify](#getmodify)|Determina se o conteúdo de um controle de edição foi modificado.|  
|[CEdit::GetPasswordChar](#getpasswordchar)|Retorna o caractere de senha exibido em um controle de edição quando o usuário insere texto.|  
|[CEdit::GetRect](#getrect)|Obtém o retângulo de formatação de um controle de edição.|  
|[CEdit::GetSel](#getsel)|Obtém as posições do primeiro e último caractere da seleção atual em um controle de edição.|  
|[CEdit::HideBalloonTip](#hideballoontip)|Oculta qualquer dica de balão associada com o controle de edição atual.|  
|[CEdit::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir em um controle de edição.|  
|[CEdit::LineFromChar](#linefromchar)|Recupera o número da linha que contém o índice do caractere especificado.|  
|[CEdit::LineIndex](#lineindex)|Recupera o índice do caractere de uma linha dentro de um controle de edição de várias linhas.|  
|[CEdit::LineLength](#linelength)|Recupera o comprimento de uma linha em um controle de edição.|  
|[CEdit::LineScroll](#linescroll)|Rola o texto de um controle de edição de várias linhas.|  
|[CEdit::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.|  
|[CEdit::PosFromChar](#posfromchar)|Recupera as coordenadas do canto superior esquerdo de um índice de caractere especificado.|  
|[CEdit::ReplaceSel](#replacesel)|Substitui a seleção atual em um controle de edição com o texto especificado.|  
|[CEdit::SetCueBanner](#setcuebanner)|Define o texto que é exibido como a sinalização de texto ou a dica em um controle de edição quando o controle está vazio e não tem o foco.|  
|[CEdit::SetHandle](#sethandle)|Define o identificador para a memória local que será usada por um controle de edição de várias linhas.|  
|[CEdit::SetHighlight](#sethighlight)|Controle de edição de realçar um intervalo de texto que é exibido no atual.|  
|[CEdit::SetLimitText](#setlimittext)|Define a quantidade máxima de texto isso `CEdit` pode conter.|  
|[CEdit::SetMargins](#setmargins)|Define as margens esquerdas e direita para este `CEdit`.|  
|[CEdit::SetModify](#setmodify)|Define ou limpa o sinalizador de modificação de um controle de edição.|  
|[CEdit::SetPasswordChar](#setpasswordchar)|Define ou remove um caractere de senha exibido em um controle de edição quando o usuário insere texto.|  
|[CEdit::SetReadOnly](#setreadonly)|Define o estado somente leitura de um controle de edição.|  
|[CEdit::SetRect](#setrect)|Define o retângulo de formatação de um controle de edição de várias linhas e atualiza o controle.|  
|[CEdit::SetRectNP](#setrectnp)|Define o retângulo de formatação de um controle de edição de várias linhas sem redesenhar a janela do controle.|  
|[CEdit::SetSel](#setsel)|Seleciona um intervalo de caracteres em um controle de edição.|  
|[CEdit::SetTabStops](#settabstops)|Controle de edição define as paradas de tabulação em várias linhas.|  
|[CEdit::ShowBalloonTip](#showballoontip)|Exibe uma dica de balão que está associada com o controle de edição atual.|  
|[CEdit::Undo](#undo)|Reverte a última operação de controle de edição.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de edição é uma janela filho retangular na qual o usuário pode digitar texto.  
  
 Você pode criar um controle de edição de um modelo de caixa de diálogo ou diretamente no seu código. Em ambos os casos, chame o construtor `CEdit` para construir o `CEdit` do objeto, em seguida, chame o [criar](#create) a função de membro para criar o Windows controle de edição e anexá-lo a `CEdit` objeto.  
  
 Construção pode ser um processo de uma etapa em uma classe derivada de `CEdit`. Escrever um construtor para a classe derivada e chamada **criar** de dentro do construtor.  
  
 `CEdit`herda a funcionalidade significativa do `CWnd`. Definir e recuperar o texto de um `CEdit` de objeto, use o `CWnd` funções de membro [SetWindowText](cwnd-class.md#setwindowtext) e [GetWindowText](cwnd-class.md#getwindowtext), que definir ou obter todo o conteúdo de um controle de edição, mesmo se ele é um controle de várias linhas. Linhas de texto em um controle de várias linhas são separadas por sequências de caracteres '\r\n'. Além disso, se um controle de edição é combinado, obter e definir uma parte do texto do controle chamando o `CEdit` funções de membro [GetLine](#getline), [SetSel](#setsel), [GetSel](#getsel), e [ReplaceSel](#replacesel).  
  
 Se você quiser controlar mensagens de notificação do Windows enviadas por um controle de edição para seu pai (normalmente uma classe derivada de `CDialog`), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa da mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem usa o seguinte formato:  
  
 **On _**notificação **(** *id, memberFxn***)**  
  
 onde `id` Especifica a ID de janela filho do controle de edição, enviando a notificação, e `memberFxn` é o nome da função de membro pai que você gravou para tratar a notificação.  
  
 Protótipo de função do pai é o seguinte:  
  
 **afx_msg** memberFxn void **();**  
  
 Esta é uma lista de entradas potenciais do mapa da mensagem e uma descrição dos casos em que eles seriam enviados ao pai:  
  
- **ON_EN_CHANGE** o usuário executou uma ação que pode ter alterado o texto em um controle de edição. Ao contrário do **EN_UPDATE** mensagem de notificação, esta mensagem de notificação é enviada após a exibição das atualizações do Windows.  
  
- **ON_EN_ERRSPACE** o controle de edição não é possível alocar memória suficiente para atender uma solicitação específica.  
  
- **ON_EN_HSCROLL** o usuário clica em barras de rolagem horizontal do controle de edição. A janela pai é notificada antes que a tela seja atualizada.  
  
- **ON_EN_KILLFOCUS** o controle de edição perde o foco de entrada.  
  
- **ON_EN_MAXTEXT** a inserção atual excedeu o número especificado de caracteres para o controle de edição e foi truncada. Também são enviadas quando um controle de edição não tem o **ES_AUTOHSCROLL** estilo e o número de caracteres a ser inserido excede a largura do controle de edição. Também são enviadas quando um controle de edição não tem o **ES_AUTOVSCROLL** estilo e o número total de linhas resultante de uma inserção de texto excede a altura do controle de edição.  
  
- **ON_EN_SETFOCUS** enviada quando um controle de edição recebe o foco de entrada.  
  
- **ON_EN_UPDATE** o controle de edição está prestes a exibir o texto alterado. Enviado após o controle tem o texto formatado, mas antes ele filtra o texto para que o tamanho da janela pode ser alterado, se necessário.  
  
- **ON_EN_VSCROLL** o usuário clica em barras de rolagem vertical do controle de edição. A janela pai é notificada antes que a tela seja atualizada.  
  
 Se você criar um `CEdit` objeto dentro de uma caixa de diálogo de `CEdit` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CEdit` objeto a partir de um recurso de caixa de diálogo usando o editor de caixa de diálogo, o `CEdit` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CEdit` do objeto em uma janela, você também precisa destruí-lo. Se você criar o `CEdit` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CEdit` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário encerra o Windows controle de edição. Se você alocar qualquer memória no `CEdit` de objeto, substituir o `CEdit` destruidor descartar as alocações.  
  
 Para modificar alguns estilos em um controle de edição (como **ES_READONLY**) você deve enviar mensagens específicas para o controle em vez de usar [ModifyStyle](cwnd-class.md#modifystyle). Consulte [Editar estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb775464) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre `CEdit`, consulte:  
  
- [Controles](../../mfc/controls-mfc.md)  
  
-   Artigo da Base de dados de Conhecimento Q259949: INFO: SetCaretPos() é não apropriado com CEdit ou controles de CRichEditCtrl  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](cobject-class.md)  
  
 [CCmdTarget](ccmdtarget-class.md)  
  
 [CWnd](cwnd-class.md)  
  
 `CEdit`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="canundo"></a>CEdit::CanUndo  
 Chame essa função para determinar se a última operação de edição pode ser desfeita.  
  
```  
BOOL CanUndo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a última operação de edição pode ser desfeita por uma chamada para o **desfazer** função de membro; 0 se ela não pode ser desfeita.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_CANUNDO](http://msdn.microsoft.com/library/windows/desktop/bb775468) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::Undo](#undo).  
  
##  <a name="cedit"></a>CEdit::CEdit  
 Constrói um objeto `CEdit`.  
  
```  
CEdit();
```  
  
### <a name="remarks"></a>Comentários  
 Use [criar](#create) para construir as janelas do controle de edição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&1;](../../mfc/reference/codesnippet/cpp/cedit-class_1.cpp)]  
  
##  <a name="charfrompos"></a>CEdit::CharFromPos  
 Chame essa função para recuperar a linha de base zero e os índices de caracteres do caractere mais próximo ponto especificado neste `CEdit` controle  
  
```  
int CharFromPos(CPoint pt) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 As coordenadas de um ponto na área cliente deste `CEdit` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de caractere na ordem de baixo **WORD**e o índice de linha na ordem de alta **WORD**.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Essa função de membro está disponível a partir Windows 95 e Windows NT 4.0.  
  
 Para obter mais informações, consulte [EM_CHARFROMPOS](http://msdn.microsoft.com/library/windows/desktop/bb761566) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&3;](../../mfc/reference/codesnippet/cpp/cedit-class_2.cpp)]  
  
##  <a name="clear"></a>CEdit::Clear  
 Chame essa função para excluir (clear) a seleção atual (se houver) no controle de edição.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 A exclusão executada pelo **limpar** podem ser desfeitas chamando o [desfazer](#undo) função de membro.  
  
 Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, chame o [Recortar](#cut) função de membro.  
  
 Para obter mais informações, consulte [WM_CLEAR](http://msdn.microsoft.com/library/windows/desktop/ms649020) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&4;](../../mfc/reference/codesnippet/cpp/cedit-class_3.cpp)]  
  
##  <a name="copy"></a>CEdit::Copy  
 Chame essa função para copiar a seleção atual (se houver) no controle de edição na área de transferência em **CF_TEXT** formato.  
  
```  
void Copy();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [WM_COPY](http://msdn.microsoft.com/library/windows/desktop/ms649022) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&5;](../../mfc/reference/codesnippet/cpp/cedit-class_4.cpp)]  
  
##  <a name="create"></a>CEdit::Create  
 Cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de edição. Aplique qualquer combinação de [Editar estilos](edit-styles.md) ao controle.  
  
 `rect`  
 Especifica o tamanho e a posição do controle de edição. Pode ser um `CRect` objeto ou `RECT` estrutura.  
  
 `pParentWnd`  
 Especifica a janela pai do controle de edição (geralmente um `CDialog`). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID. do controle de edição  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CEdit` objeto em duas etapas. Primeiro, chame o `CEdit` construtor e em seguida, chame **criar**, que cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](http://msdn.microsoft.com/library/windows/desktop/ms632635), [WM_NCCALCSIZE](http://msdn.microsoft.com/library/windows/desktop/ms632634), [WM_CREATE](http://msdn.microsoft.com/library/windows/desktop/ms632619), e [WM_GETMINMAXINFO](http://msdn.microsoft.com/library/windows/desktop/ms632626) mensagens para o controle de edição.  
  
 Essas mensagens são manipuladas por padrão, o [OnNcCreate](cwnd-class.md#onnccreate), [OnNcCalcSize](cwnd-class.md#onnccalcsize), [OnCreate](cwnd-class.md#oncreate), e [OnGetMinMaxInfo](cwnd-class.md#ongetminmaxinfo) funções de membro na `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CEdit`, adicione um mapa da mensagem para a nova classe e substituir as funções de membro acima do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para a nova classe.  
  
 Aplique o seguinte [estilos de janela](window-styles.md) para um controle de edição.  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
- **WS_GROUP** para agrupar controles  
  
- **WS_TABSTOP** para incluir o controle de edição na ordem de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&2;](../../mfc/reference/codesnippet/cpp/cedit-class_5.cpp)]  
  
##  <a name="cut"></a>CEdit::Cut  
 Chame essa função para excluir (Recortar) a seleção atual (se houver) no controle de edição e copie o texto excluído na área de transferência em **CF_TEXT** formato.  
  
```  
void Cut();
```  
  
### <a name="remarks"></a>Comentários  
 A exclusão executada pelo **Recortar** podem ser desfeitas chamando o [desfazer](#undo) função de membro.  
  
 Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [limpar](#clear) função de membro.  
  
 Para obter mais informações, consulte [WM_CUT](http://msdn.microsoft.com/library/windows/desktop/ms649023) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&6;](../../mfc/reference/codesnippet/cpp/cedit-class_6.cpp)]  
  
##  <a name="emptyundobuffer"></a>CEdit::EmptyUndoBuffer  
 Chame essa função para redefinir (limpar) o sinalizador de recuperação de um controle de edição.  
  
```  
void EmptyUndoBuffer();
```  
  
### <a name="remarks"></a>Comentários  
 O controle de edição agora será possível desfazer a última operação. O sinalizador de desfazer é definido sempre que uma operação dentro do controle de edição pode ser desfeita.  
  
 O sinalizador de desfazer é automaticamente limpo sempre que o [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) ou [SetHandle](#sethandle) `CWnd` são chamadas de funções de membro.  
  
 Para obter mais informações, consulte [EM_EMPTYUNDOBUFFER](http://msdn.microsoft.com/library/windows/desktop/bb761568) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#7;](../../mfc/reference/codesnippet/cpp/cedit-class_7.cpp)]  
  
##  <a name="fmtlines"></a>CEdit::FmtLines  
 Chame essa função para definir a inclusão de caracteres de quebra de linha suave ou desativar dentro de um controle de edição de várias linhas.  
  
```  
BOOL FmtLines(BOOL bAddEOL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAddEOL*  
 Especifica se os caracteres de quebra de linha flexível a ser inserido. Um valor de **TRUE** insere os caracteres; um valor de **FALSE** removê-los.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se qualquer formatação ocorre; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma quebra de linha manual consiste em dois retornos de carro e alimentação de linhas inserido no final de uma linha que foi interrompida devido a quebra de texto. Uma quebra de linha rígido consiste em um retorno de carro e alimentação de linhas. Linhas que terminam com uma quebra de linha definida não são afetadas por `FmtLines`.  
  
 Windows só responderá se o `CEdit` objeto é um controle de edição de várias linhas.  
  
 `FmtLines`afeta somente o buffer retornado por [GetHandle](#gethandle) e o texto retornado por [WM_GETTEXT](http://msdn.microsoft.com/library/windows/desktop/ms632627). Ele não tem impacto sobre a exibição do texto dentro do controle de edição.  
  
 Para obter mais informações, consulte [EM_FMTLINES](http://msdn.microsoft.com/library/windows/desktop/bb761570) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&8;](../../mfc/reference/codesnippet/cpp/cedit-class_8.cpp)]  
  
##  <a name="getcuebanner"></a>CEdit::GetCueBanner  
 Recupera o texto que é exibido como a sinalização de texto ou dica, em um controle de edição quando o controle estiver vazio.  
  
```  
BOOL GetCueBanner(
    LPWSTR lpszText,  
    int cchText) const;  
  
CString GetCueBanner() const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lpszText`  
 Um ponteiro para uma cadeia de caracteres que contém o texto de indicação.  
  
 [in] `cchText`  
 O número de caracteres que pode ser recebido. Esse número inclui a terminação `NULL` caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Para a primeira sobrecarga, `true` se o método for bem-sucedido; caso contrário `false`.  
  
 Para a segunda sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de indicação se o método for bem-sucedido; caso contrário, a cadeia de caracteres vazia ("").  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [EM_GETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb761572) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Para obter mais informações, consulte o [Edit_GetCueBannerText](http://msdn.microsoft.com/library/windows/desktop/bb761695) macro.  
  
##  <a name="getfirstvisibleline"></a>CEdit::GetFirstVisibleLine  
 Chame essa função para determinar a linha superior visível em um controle de edição.  
  
```  
int GetFirstVisibleLine() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da primeira linha visível. Para controles de edição de linha única, o valor de retorno é 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_GETFIRSTVISIBLELINE](http://msdn.microsoft.com/library/windows/desktop/bb761574) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&9;](../../mfc/reference/codesnippet/cpp/cedit-class_9.cpp)]  
  
##  <a name="gethandle"></a>CEdit::GetHandle  
 Chame essa função para recuperar um identificador para a memória alocada atualmente para um controle de edição de várias linhas.  
  
```  
HLOCAL GetHandle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador de memória local que identifica o buffer que mantém o conteúdo do controle de edição. Se ocorrer um erro, como enviar a mensagem para um controle de edição de linha única, o valor de retorno será 0.  
  
### <a name="remarks"></a>Comentários  
 O identificador é um identificador de memória local e podem ser usado por qualquer uma da **Local** manipulam funções de memória do Windows que usam um local de memória como um parâmetro.  
  
 **GetHandle** é processada apenas por controles de edição de várias linhas.  
  
 Chamar **GetHandle** para um controle de edição de várias linhas em uma caixa de diálogo somente se a caixa de diálogo foi criada com o **DS_LOCALEDIT** conjunto de sinalizadores de estilo. Se o **DS_LOCALEDIT** estilo não é definido, você ainda terá um valor de retorno diferente de zero, mas você não poderá usar o valor retornado.  
  
> [!NOTE]
> **GetHandle** não funciona com o Windows 95/98. Se você chamar **GetHandle** no Windows 95/98, ele retornará **nulo**. **GetHandle** funcionará conforme documentado no Windows NT, versões 3.51 e posteriores.  
  
 Para obter mais informações, consulte [EM_GETHANDLE](http://msdn.microsoft.com/library/windows/desktop/bb761576) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&10;](../../mfc/reference/codesnippet/cpp/cedit-class_10.cpp)]  
  
##  <a name="gethighlight"></a>CEdit::GetHighlight  
 Obtém os índices do primeiro e último caracteres em um intervalo de texto é realçado no controle de edição atual.  
  
```  
BOOL GetHighlight(
    int* pichStart,   
    int* pichEnd) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `pichStart`|Índice baseado em zero do primeiro caractere no intervalo de texto é realçado.|  
|[out] `pichEnd`|Índice baseado em zero do último caractere no intervalo de texto é realçado.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [EM_GETHILITE](http://msdn.microsoft.com/library/windows/desktop/bb761578) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getlimittext"></a>CEdit::GetLimitText  
 Chame essa função de membro para obter o limite de texto para isso `CEdit` objeto.  
  
```  
UINT GetLimitText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O texto limite atual, em bytes, para que isso `CEdit` objeto.  
  
### <a name="remarks"></a>Comentários  
 O limite de texto é a quantidade máxima de texto, em bytes, que pode aceitar o controle de edição.  
  
> [!NOTE]
>  Essa função de membro está disponível a partir Windows 95 e Windows NT 4.0.  
  
 Para obter mais informações, consulte [EM_GETLIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb761582) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&11;](../../mfc/reference/codesnippet/cpp/cedit-class_11.cpp)]  
  
##  <a name="getline"></a>CEdit::GetLine  
 Chame essa função para recuperar uma linha de texto de um controle de edição e o coloca em `lpszBuffer`.  
  
```  
int GetLine(
    int nIndex,  
    LPTSTR lpszBuffer) const;  
  
int GetLine(
    int nIndex,  
    LPTSTR lpszBuffer,  
    int nMaxLength) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o número da linha para recuperar de várias linhas de controle de edição. Números de linha são baseadas em zero; um valor de 0 especifica a primeira linha. Esse parâmetro é ignorado por um controle de edição de linha única.  
  
 `lpszBuffer`  
 Aponta para o buffer que recebe uma cópia da linha. A primeira palavra do buffer deve especificar o número máximo de caracteres que podem ser copiados para o buffer.  
  
 `nMaxLength`  
 Especifica o número máximo de bytes que pode ser copiado para o buffer. `GetLine`coloca esse valor da primeira palavra de `lpszBuffer` antes de fazer a chamada para o Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes realmente copiado. O valor de retorno será 0 se o número de linhas especificado pelo `nIndex` é maior que o número de linhas no controle de edição.  
  
### <a name="remarks"></a>Comentários  
 A linha copiada não contiver um caractere de finalização null.  
  
 Para obter mais informações, consulte [EM_GETLINE](http://msdn.microsoft.com/library/windows/desktop/bb761584) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::GetLineCount](#getlinecount).  
  
##  <a name="getlinecount"></a>CEdit::GetLineCount  
 Chame essa função para recuperar o número de linhas em um controle de edição de várias linhas.  
  
```  
int GetLineCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Controle de edição de um inteiro contendo o número de linhas em várias linhas. Caso nenhum texto tenha sido inserido no controle de edição, o valor de retorno é 1.  
  
### <a name="remarks"></a>Comentários  
 `GetLineCount`só é processada por controles de edição de várias linhas.  
  
 Para obter mais informações, consulte [EM_GETLINECOUNT](http://msdn.microsoft.com/library/windows/desktop/bb761586) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#12;](../../mfc/reference/codesnippet/cpp/cedit-class_12.cpp)]  
  
##  <a name="getmargins"></a>CEdit::GetMargins  
 Chame essa função de membro para recuperar as margens esquerdas e direita desse controle de edição.  
  
```  
DWORD GetMargins() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da margem esquerda na ordem de baixo **WORD** e a largura da margem direita na ordem alta **WORD**.  
  
### <a name="remarks"></a>Comentários  
 As margens são medidas em pixels.  
  
> [!NOTE]
>  Essa função de membro está disponível a partir Windows 95 e Windows NT 4.0.  
  
 Para obter mais informações, consulte [EM_GETMARGINS](http://msdn.microsoft.com/library/windows/desktop/bb761590) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).  
  
##  <a name="getmodify"></a>CEdit::GetModify  
 Chame essa função para determinar se o conteúdo de um controle de edição foi modificado.  
  
```  
BOOL GetModify() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o conteúdo do controle de edição foi modificado; 0 se eles permanecem inalterados.  
  
### <a name="remarks"></a>Comentários  
 O Windows mantém um sinalizador interno que indica se o conteúdo do controle de edição foram alterado. Esse sinalizador é apagado quando o controle de edição é primeiro criado e também pode ser eliminado chamando o [SetModify](#setmodify) função de membro.  
  
 Para obter mais informações, consulte [EM_GETMODIFY](http://msdn.microsoft.com/library/windows/desktop/bb761592) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&13;](../../mfc/reference/codesnippet/cpp/cedit-class_13.cpp)]  
  
##  <a name="getpasswordchar"></a>CEdit::GetPasswordChar  
 Chame essa função para recuperar o caractere de senha é exibido em um controle de edição quando o usuário insere texto.  
  
```  
TCHAR GetPasswordChar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Especifica o caractere a ser exibido em vez do caractere digitado pelo usuário. O valor de retorno é `NULL` não se existir nenhum caractere de senha.  
  
### <a name="remarks"></a>Comentários  
 Se você criar o controle de edição com o **ES_PASSWORD** o estilo, a DLL que oferece suporte o controle determina o caractere padrão de senha. O manifesto ou o [InitCommonControlsEx](http://msdn.microsoft.com/library/windows/desktop/bb775697) método determina qual DLL dá suporte o controle de edição. Se User32. dll oferecer suporte ao controle de edição, o caractere de senha padrão é asterisco ('* ', U +&002;A). Se Comctl32. dll versão 6 oferece suporte a controle de edição, o caractere padrão é CÍRCULO preto ('●', U + 25CF). Para obter mais informações sobre o que dá suporte a DLL e a versão de controles comuns, consulte [Shell e versões de controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb776779).  
  
 Esse método envia o [EM_GETPASSWORDCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761594) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#14;](../../mfc/reference/codesnippet/cpp/cedit-class_14.cpp)]  
  
##  <a name="getrect"></a>CEdit::GetRect  
 Chame essa função para obter o retângulo de formatação de um controle de edição.  
  
```  
void GetRect(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para a `RECT` estrutura que recebe o retângulo de formatação.  
  
### <a name="remarks"></a>Comentários  
 O retângulo de formatação é o limitação retângulo do texto, que é independente do tamanho da janela de controle de edição.  
  
 O retângulo de formatação de um controle de edição de várias linhas pode ser modificado pelo [SetRect](#setrect) e [SetRectNP](#setrectnp) funções de membro.  
  
 Para obter mais informações, consulte [EM_GETRECT](http://msdn.microsoft.com/library/windows/desktop/bb761596) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::LimitText](#limittext).  
  
##  <a name="getsel"></a>CEdit::GetSel  
 Chame essa função para obter inicial e final posições de caractere da seleção atual (se houver) em um controle de edição, usando o valor de retorno ou os parâmetros.  
  
```  
DWORD GetSel() const;  
  
void GetSel(
    int& nStartChar,  
    int& nEndChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartChar`  
 Referência a um número inteiro que receberá a posição do primeiro caractere na seleção atual.  
  
 `nEndChar`  
 Referência a um número inteiro que receberá a posição do primeiro caractere não selecionado após o final da seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 A versão que retorna um `DWORD` retorna um valor que contém a posição inicial da palavra de ordem inferior e a posição do primeiro caractere não selecionado após o final da seleção da palavra de ordem superior.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_GETSEL](http://msdn.microsoft.com/library/windows/desktop/bb761598) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#15;](../../mfc/reference/codesnippet/cpp/cedit-class_15.cpp)]  
  
##  <a name="hideballoontip"></a>CEdit::HideBalloonTip  
 Oculta qualquer dica de balão associada com o controle de edição atual.  
  
```  
BOOL HideBalloonTip();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Essa função envia o [EM_HIDEBALLOONTIP](http://msdn.microsoft.com/library/windows/desktop/bb761604) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="limittext"></a>CEdit::LimitText  
 Chame essa função para limitar o tamanho do texto que o usuário pode inserir em um controle de edição.  
  
```  
void LimitText(int nChars = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChars`  
 Especifica o comprimento (em bytes) do que o usuário pode digitar texto. Se esse parâmetro for 0, o comprimento do texto é definido como **UINT_MAX** bytes. Este é o comportamento padrão.  
  
### <a name="remarks"></a>Comentários  
 Alterar o limite de texto restringe somente o texto que o usuário pode inserir. Não tem nenhum efeito em qualquer texto já no controle de edição, nem afeta o tamanho do texto copiado para o controle de edição, o [SetWindowText](cwnd-class.md#setwindowtext) função de membro em `CWnd`. Se um aplicativo usa o `SetWindowText` função colocar mais texto em um controle de edição que é especificado na chamada para `LimitText`, o usuário pode excluir o texto dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substituindo o texto existente pelo novo texto, a menos que excluindo a seleção atual faz com que o texto esteja abaixo do limite de texto.  
  
> [!NOTE]
>  No Win32 (Windows NT e Windows 95/98) [SetLimitText](#setlimittext) substitui essa função.  
  
 Para obter mais informações, consulte [EM_LIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb761607) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFC_CEdit](../../mfc/reference/codesnippet/cpp/cedit-class_16.cpp)]  
  
##  <a name="linefromchar"></a>CEdit::LineFromChar  
 Chame essa função para recuperar o número de linha da linha que contém o índice do caractere especificado.  
  
```  
int LineFromChar(int nIndex = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o valor de índice baseado em zero para o caractere desejado no texto do controle de edição ou contém –&1;. Se `nIndex` é –&1;, ele especifica a linha atual, ou seja, a linha que contém o cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O número da linha de base zero da linha que contém o índice do caractere especificado por `nIndex`. Se `nIndex` é –&1;, o número da linha que contém o primeiro caractere da seleção é retornado. Se não houver nenhuma seleção, o número da linha atual será retornado.  
  
### <a name="remarks"></a>Comentários  
 Um índice de caractere é o número de caracteres do início do controle de edição.  
  
 Essa função de membro só é usada por controles de edição de várias linhas.  
  
 Para obter mais informações, consulte [EM_LINEFROMCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761609) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&18;](../../mfc/reference/codesnippet/cpp/cedit-class_17.cpp)]  
  
##  <a name="lineindex"></a>CEdit::LineIndex  
 Chame essa função para recuperar o índice do caractere de uma linha dentro de um controle de edição de várias linhas.  
  
```  
int LineIndex(int nLine = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLine`  
 Contém o valor de índice de linha desejada no texto do controle de edição ou contém –&1;. Se `nLine` é –&1;, ele especifica a linha atual, ou seja, a linha que contém o cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do caractere da linha especificada no `nLine` ou -1 se o número de linha especificado é maior que o número de linhas no controle de edição.  
  
### <a name="remarks"></a>Comentários  
 O índice do caractere é o número de caracteres do início do controle de edição para a linha especificada.  
  
 Essa função de membro só é processada por controles de edição de várias linhas.  
  
 Para obter mais informações, consulte [EM_LINEINDEX](http://msdn.microsoft.com/library/windows/desktop/bb761611) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFC_CEdit](../../mfc/reference/codesnippet/cpp/cedit-class_18.cpp)]  
  
##  <a name="linelength"></a>CEdit::LineLength  
 Recupera o comprimento de uma linha em um controle de edição.  
  
```  
int LineLength(int nLine = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLine`  
 O índice com base em zero de um caractere na linha cujo tamanho deve ser recuperado. O valor padrão é -1.  
  
### <a name="return-value"></a>Valor de retorno  
 Para controles de edição de linha única, o valor de retorno é o comprimento, em `TCHAR`s, do texto no controle de edição.  
  
 Para controles de edição de várias linhas, o valor de retorno é o comprimento, em `TCHAR`s, da linha especificada pelo `nLine` parâmetro. Para [!INCLUDE[vcpransi](../../atl-mfc-shared/reference/includes/vcpransi_md.md)] texto, o comprimento é o número de bytes na linha; para texto em Unicode, o comprimento é o número de caracteres na linha. O comprimento não incluir o caractere de retorno de carro no final da linha.  
  
 Se o `nLine` parâmetro for maior que o número de caracteres no controle, o valor de retorno é zero.  
  
 Se o `nLine` parâmetro é –&1;, o valor de retorno é o número de caracteres não selecionados em linhas que contêm caracteres selecionados. Por exemplo, se estende a seleção do quarto caractere de uma linha, o caractere oitavo do final da próxima linha, o valor de retorno é 10. Isto é, os três caracteres na primeira linha e sete na próxima.  
  
 Para obter mais informações sobre o `TCHAR` tipo, consulte o `TCHAR` linha na tabela [tipos de dados do Windows](http://msdn.microsoft.com/library/windows/desktop/aa383751).  
  
### <a name="remarks"></a>Comentários  
 Este método é suportado pelo [EM_LINELENGTH](http://msdn.microsoft.com/library/windows/desktop/bb761613) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::LineIndex](#lineindex).  
  
##  <a name="linescroll"></a>CEdit::LineScroll  
 Chame essa função para rolar o texto de um controle de edição de várias linhas.  
  
```  
void LineScroll(
    int nLines,  
    int nChars = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLines`  
 Especifica o número de linhas para rolar verticalmente.  
  
 `nChars`  
 Especifica o número de posições de caractere para rolar horizontalmente. Esse valor é ignorado se o controle de edição tem o **ES_RIGHT** ou **ES_CENTER** estilo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é processada apenas por controles de edição de várias linhas.  
  
 O controle de edição não rola verticalmente após a última linha do texto no controle de edição. Se a linha atual mais o número de linhas especificado pelo `nLines` excede o número total de linhas no controle de edição, o valor é ajustado para que a última linha do controle de edição é rolada para a parte superior da janela de controle de edição.  
  
 `LineScroll`pode ser usado para rolar horizontalmente após o último caractere de qualquer linha.  
  
 Para obter mais informações, consulte [EM_LINESCROLL](http://msdn.microsoft.com/library/windows/desktop/bb761615) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::GetFirstVisibleLine](#getfirstvisibleline).  
  
##  <a name="paste"></a>CEdit::Paste  
 Chame essa função para inserir os dados da área de transferência para o `CEdit` no ponto de inserção.  
  
```  
void Paste();
```  
  
### <a name="remarks"></a>Comentários  
 Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.  
  
 Para obter mais informações, consulte [WM_PASTE](http://msdn.microsoft.com/library/windows/desktop/ms649028) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_MFC_CEdit](../../mfc/reference/codesnippet/cpp/cedit-class_19.cpp)]  
  
##  <a name="posfromchar"></a>CEdit::PosFromChar  
 Chame essa função para obter a posição (canto superior esquerdo) de um determinado caractere dentro dessa `CEdit` objeto.  
  
```  
CPoint PosFromChar(UINT nChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 O índice baseado em zero do caractere especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 As coordenadas do canto superior esquerdo do caractere especificado por `nChar`.  
  
### <a name="remarks"></a>Comentários  
 O caractere for especificado, fornecendo seu valor de índice baseado em zero. Se `nChar` é maior do que o índice do último caractere na `CEdit` do objeto, o valor de retorno Especifica as coordenadas de posição do caractere apenas após o último caractere no `CEdit` objeto.  
  
> [!NOTE]
>  Essa função de membro está disponível a partir Windows 95 e Windows NT 4.0.  
  
 Para obter mais informações, consulte [EM_POSFROMCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761631) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::LineFromChar](#linefromchar).  
  
##  <a name="replacesel"></a>CEdit::ReplaceSel  
 Chame essa função para substituir a seleção atual em um controle de edição com o texto especificado por `lpszNewText`.  
  
```  
void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszNewText`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o texto de substituição.  
  
 `bCanUndo`  
 Para especificar que essa função pode ser desfeita, defina o valor desse parâmetro para **TRUE** . O valor padrão é **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Substitui apenas uma parte do texto em um controle de edição. Se você deseja substituir todo o texto, use o [CWnd::SetWindowText](cwnd-class.md#setwindowtext) função de membro.  
  
 Se não houver nenhuma seleção atual, o texto de substituição é inserido na posição atual do cursor.  
  
 Para obter mais informações, consulte [EM_REPLACESEL](http://msdn.microsoft.com/library/windows/desktop/bb761633) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::LineIndex](#lineindex).  
  
##  <a name="setcuebanner"></a>CEdit::SetCueBanner  
 Define o texto que é exibido como a indicação de texto, ou dica, em uma edição de controle quando o controle está vazio.  
  
```  
BOOL SetCueBanner(LPCWSTR lpszText);

 
BOOL SetCueBanner(
    LPCWSTR lpszText,   
    BOOL fDrawWhenFocused = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszText`  
 Ponteiro para uma cadeia de caracteres que contém a indicação para exibir no controle de edição.  
  
 [in] `fDrawWhenFocused`  
 Se `false`, a faixa de indicação não é desenhada quando o usuário clica no controle de edição e fornece o controle do foco.  
  
 Se `true`, a faixa de indicação é desenhada, mesmo quando o controle tem o foco. A faixa de indicação desaparece quando o usuário começa a digitar no controle.  
  
 O valor padrão é `false`.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o método for bem-sucedido; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [EM_SETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb761639) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Para obter mais informações, consulte o [Edit_SetCueBannerTextFocused](http://msdn.microsoft.com/library/windows/desktop/bb761703) macro.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o [CEdit::SetCueBanner](#setcuebanner) método.  
  
 [!code-cpp[NVC_MFC_CEdit_s1 n º&2;](../../mfc/reference/codesnippet/cpp/cedit-class_20.cpp)]  
  
##  <a name="sethandle"></a>CEdit::SetHandle  
 Chame essa função para definir o identificador para a memória local que será usada por um controle de edição de várias linhas.  
  
```  
void SetHandle(HLOCAL hBuffer);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hBuffer*  
 Contém um identificador para a memória local. Esse identificador deve ter sido criado por uma chamada anterior a [LocalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366723) função do Windows usando o **LMEM_MOVEABLE** sinalizador. A memória deve para conter uma cadeia de caracteres terminada em nulo. Se esse não for o caso, o primeiro byte da memória alocada deve ser definido como 0.  
  
### <a name="remarks"></a>Comentários  
 O controle de edição, em seguida, usará esse buffer para armazenar o texto exibido no momento em vez de alocar o próprio buffer.  
  
 Essa função de membro é processada apenas por controles de edição de várias linhas.  
  
 Antes de um aplicativo define um novo identificador de memória, ele deve usar o [GetHandle](#gethandle) a função de membro para obter o identificador para o buffer de memória atual e liberar essa memória usando o **LocalFree** função do Windows.  
  
 `SetHandle`Limpa o buffer de desfazer (o [CanUndo](#canundo) função membro retorna 0) e o sinalizador interno de modificação (o [GetModify](#getmodify) função membro retorna 0). A janela de controle de edição é redesenhada.  
  
 Você pode usar essa função de membro em um controle de edição de várias linhas em uma caixa de diálogo somente se você tiver criado a caixa de diálogo com o **DS_LOCALEDIT** conjunto de sinalizadores de estilo.  
  
> [!NOTE]
> **GetHandle** não funciona com o Windows 95/98. Se você chamar **GetHandle** no Windows 95/98, ele retornará **nulo**. **GetHandle** funcionará conforme documentado no Windows NT, versões 3.51 e posteriores.  
  
 Para obter mais informações, consulte [EM_SETHANDLE](http://msdn.microsoft.com/library/windows/desktop/bb761641), [LocalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366723), e [LocalFree](http://msdn.microsoft.com/library/windows/desktop/aa366730) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#22;](../../mfc/reference/codesnippet/cpp/cedit-class_21.cpp)]  
  
##  <a name="sethighlight"></a>CEdit::SetHighlight  
 Controle de edição de realçar um intervalo de texto que é exibido no atual.  
  
```  
void SetHighlight(
    int ichStart,   
    int ichEnd);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `ichStart`|Índice baseado em zero do primeiro caractere no intervalo de texto a ser realçado.|  
|[in] `ichEnd`|Índice baseado em zero do último caractere no intervalo de texto a ser realçado.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [EM_SETHILITE](http://msdn.microsoft.com/library/windows/desktop/bb761643) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setlimittext"></a>CEdit::SetLimitText  
 Chame essa função de membro para definir o limite de texto para isso `CEdit` objeto.  
  
```  
void SetLimitText(UINT nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMax`  
 O novo limite de texto, em caracteres.  
  
### <a name="remarks"></a>Comentários  
 O limite de texto é a quantidade máxima de texto, em caracteres, que pode aceitar o controle de edição.  
  
 Alterar o limite de texto restringe somente o texto que o usuário pode inserir. Não tem nenhum efeito em qualquer texto já no controle de edição, nem afeta o tamanho do texto copiado para o controle de edição, o [SetWindowText](cwnd-class.md#setwindowtext) função de membro em `CWnd`. Se um aplicativo usa o `SetWindowText` função colocar mais texto em um controle de edição que é especificado na chamada para `LimitText`, o usuário pode excluir o texto dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substituindo o texto existente pelo novo texto, a menos que excluindo a seleção atual faz com que o texto esteja abaixo do limite de texto.  
  
 Esta função substitui [LimitText](#limittext) no Win32.  
  
 Para obter mais informações, consulte [EM_SETLIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb761647) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).  
  
##  <a name="setmargins"></a>CEdit::SetMargins  
 Chame esse método para definir as margens esquerdas e direita desse controle de edição.  
  
```  
void SetMargins(
    UINT nLeft,  
    UINT nRight);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nLeft*  
 A largura da margem esquerda novo, em pixels.  
  
 *nRight*  
 A largura da margem direita novo, em pixels.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Essa função de membro está disponível a partir Windows 95 e Windows NT 4.0.  
  
 Para obter mais informações, consulte [EM_SETMARGINS](http://msdn.microsoft.com/library/windows/desktop/bb761649) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).  
  
##  <a name="setmodify"></a>CEdit::SetModify  
 Chame essa função para definir ou limpar o sinalizador modificado para um controle de edição.  
  
```  
void SetModify(BOOL bModified = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bModified`  
 Um valor de **TRUE** indica que o texto foi modificado e um valor de **FALSE** indica é inalterado. Por padrão, o sinalizador modificado é definido.  
  
### <a name="remarks"></a>Comentários  
 O sinalizador modificado indica se o texto dentro do controle de edição foi modificado. Ela é definida automaticamente sempre que o usuário altera o texto. Seu valor pode ser recuperado com o [GetModify](#getmodify) função de membro.  
  
 Para obter mais informações, consulte [EM_SETMODIFY](http://msdn.microsoft.com/library/windows/desktop/bb761651) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::GetModify](#getmodify).  
  
##  <a name="setpasswordchar"></a>CEdit::SetPasswordChar  
 Chame essa função para definir ou remover um caractere de senha exibido em um controle de edição quando o usuário digita texto.  
  
```  
void SetPasswordChar(TCHAR ch);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CH*  
 Especifica o caractere a ser exibido no lugar do caractere digitado pelo usuário. Se *ch* for 0, os caracteres reais digitados pelo usuário são exibidos.  
  
### <a name="remarks"></a>Comentários  
 Quando um caractere de senha é definido, esse caractere é exibido para cada caractere que o usuário digita.  
  
 Essa função de membro não tem nenhum efeito em várias linhas controle de edição.  
  
 Quando o `SetPasswordChar` é chamada de função de membro, `CEdit` redesenhará todos os caracteres visíveis usando o caractere especificado por *ch*.  
  
 Se o controle de edição é criado com o [ES_PASSWORD](edit-styles.md) estilo, o caractere de senha padrão é definido como um asterisco ( ** \* **). Esse estilo será removido se `SetPasswordChar` é chamado com *ch* definido como 0.  
  
 Para obter mais informações, consulte [EM_SETPASSWORDCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761653) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit n º&16;](../../mfc/reference/codesnippet/cpp/cedit-class_22.cpp)]  
  
##  <a name="setreadonly"></a>CEdit::SetReadOnly  
 Chama essa função para definir o estado somente leitura de um controle de edição.  
  
```  
BOOL SetReadOnly(BOOL bReadOnly = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bReadOnly`  
 Especifica se deve definir ou remover o estado somente leitura no controle de edição. Um valor de **TRUE** define o estado como somente leitura; um valor de **FALSE** define o estado de leitura/gravação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação for bem-sucedida, ou 0 se um erro ocorre.  
  
### <a name="remarks"></a>Comentários  
 A configuração atual pode ser encontrada pelo teste de [ES_READONLY](edit-styles.md) sinalizador no valor de retorno de [CWnd::GetStyle](cwnd-class.md#getstyle).  
  
 Para obter mais informações, consulte [EM_SETREADONLY](http://msdn.microsoft.com/library/windows/desktop/bb761655) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#23;](../../mfc/reference/codesnippet/cpp/cedit-class_23.cpp)]  
  
##  <a name="setrect"></a>CEdit::SetRect  
 Chame essa função para definir as dimensões de um retângulo usando coordenadas especificadas.  
  
```  
void SetRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para a `RECT` estrutura ou `CRect` objeto que especifica as novas dimensões do retângulo de formatação.  
  
### <a name="remarks"></a>Comentários  
 Esse membro é processado apenas por controles de edição de várias linhas.  
  
 Use `SetRect` para definir a formatação de controle de edição do retângulo de várias linhas. O retângulo de formatação é o limitação retângulo do texto, que é independente do tamanho da janela de controle de edição. Quando o controle de edição é criado, o retângulo formatação é o mesmo que a área do cliente da janela do controle de edição. Usando o `SetRect` função de membro, um aplicativo pode fazer o retângulo formatação maior ou menor que a janela de controle de edição.  
  
 Se o controle de edição não tiver nenhuma barra de rolagem, texto será recortado, não encapsulados, se o retângulo formatação fica maior que a janela. Se o controle de edição contiver uma borda, o retângulo formatação é reduzido pelo tamanho da borda. Se você ajustar o retângulo retornado pelo `GetRect` função de membro, você deve remover o tamanho da borda antes de passar o retângulo para `SetRect`.  
  
 Quando `SetRect` é chamado, o controle de edição do texto é reformatado e reexibido também.  
  
 Para obter mais informações, consulte [EM_SETRECT](http://msdn.microsoft.com/library/windows/desktop/bb761657) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CEdit&#24;](../../mfc/reference/codesnippet/cpp/cedit-class_24.cpp)]  
  
##  <a name="setrectnp"></a>CEdit::SetRectNP  
 Chame essa função para definir o retângulo de formatação de um controle de edição de várias linhas.  
  
```  
void SetRectNP(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `RECT` estrutura ou `CRect` objeto que especifica as novas dimensões do retângulo.  
  
### <a name="remarks"></a>Comentários  
 O retângulo de formatação é o limitação retângulo do texto, que é independente do tamanho da janela de controle de edição.  
  
 `SetRectNP`é idêntico de `SetRect` função do membro exceto que a janela de controle de edição não é redesenhada.  
  
 Quando o controle de edição é criado, o retângulo formatação é o mesmo que a área do cliente da janela do controle de edição. Chamando o `SetRectNP` função de membro, um aplicativo pode fazer o retângulo formatação maior ou menor que a janela de controle de edição.  
  
 Se o controle de edição não tiver nenhuma barra de rolagem, texto será recortado, não encapsulados, se o retângulo formatação fica maior que a janela.  
  
 Esse membro é processado apenas por controles de edição de várias linhas.  
  
 Para obter mais informações, consulte [EM_SETRECTNP](http://msdn.microsoft.com/library/windows/desktop/bb761659) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::SetRect](#setrect).  
  
##  <a name="setsel"></a>CEdit::SetSel  
 Chame essa função para selecionar um intervalo de caracteres em um controle de edição.  
  
```  
void SetSel(
    DWORD dwSelection,  
    BOOL bNoScroll = FALSE);

 
void SetSel(
    int nStartChar,  
    int nEndChar,  
    BOOL bNoScroll = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwSelection*  
 Especifica a posição inicial da palavra de ordem inferior e a posição final da palavra de ordem superior. Se a palavra de ordem inferior é 0 e a palavra de ordem superior é -1, todo o texto no controle de edição é selecionado. Se a palavra de ordem inferior é –&1;, qualquer seleção atual será removida.  
  
 *bNoScroll*  
 Indica se o cursor deve ser colocado na exibição. Se **FALSE**, o cursor é colocado na exibição. Se **TRUE**, o cursor não é colocado na exibição.  
  
 `nStartChar`  
 Especifica a posição inicial. Se `nStartChar` é 0 e `nEndChar` é – 1, todos o texto no controle de edição é selecionado. Se `nStartChar` é –&1;, qualquer seleção atual é removida.  
  
 `nEndChar`  
 Especifica a posição final.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_SETSEL](http://msdn.microsoft.com/library/windows/desktop/bb761661) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEdit::GetSel](#getsel).  
  
##  <a name="settabstops"></a>CEdit::SetTabStops  
 Chame essa função para definir as paradas de tabulação em um controle de edição de várias linhas.  
  
```  
void SetTabStops();  
BOOL SetTabStops(const int& cxEachStop);

 
BOOL SetTabStops(
    int nTabStops,  
    LPINT rgTabStops);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxEachStop`  
 Especifica que as paradas de tabulação devem ser definidas em cada `cxEachStop` unidades de diálogo.  
  
 `nTabStops`  
 Especifica o número de paradas de tabulação contidas no `rgTabStops`. Esse número deve ser maior que 1.  
  
 `rgTabStops`  
 Aponta para uma matriz de inteiros sem sinal especificando a guia para em unidades de diálogo. Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura de base da caixa de diálogo atual e 1 unidade de diálogo vertical é igual a um oitavo da unidade de base altura da caixa de diálogo atual. As unidades base da caixa de diálogo são calculadas com base na altura e largura da fonte atual do sistema. O **GetDialogBaseUnits** função Windows retorna a caixa de diálogo atual unidades base em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o guias foram definidas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Quando o texto é copiado para um controle de edição de várias linhas, qualquer caractere de tabulação no texto fará com que o espaço a ser gerado até a próxima parada de tabulação.  
  
 Para definir paradas de tabulação para o tamanho padrão de 32 unidades de caixa de diálogo, chame a versão sem parâmetros dessa função de membro. Para definir paradas de tabulação em um tamanho diferente de 32, chame a versão com o `cxEachStop` parâmetro. Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com dois parâmetros.  
  
 Essa função de membro só é processada por controles de edição de várias linhas.  
  
 `SetTabStops`não atualiza automaticamente a janela de edição. Se você alterar as paradas de tabulação para texto já no controle de edição, chame [CWnd::InvalidateRect](cwnd-class.md#invalidaterect) para redesenhar a janela de edição.  
  
 Para obter mais informações, consulte [EM_SETTABSTOPS](http://msdn.microsoft.com/library/windows/desktop/bb761663) e [GetDialogBaseUnits](http://msdn.microsoft.com/library/windows/desktop/ms645475) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CEditView::SetTabStops](ceditview-class.md#settabstops).  
  
##  <a name="showballoontip"></a>CEdit::ShowBalloonTip  
 Exibe uma dica de balão que está associada com o controle de edição atual.  
  
```  
BOOL ShowBalloonTip(PEDITBALLOONTIP pEditBalloonTip);

 
BOOL ShowBalloonTip(
    LPCWSTR lpszTitle,   
    LPCWSTR lpszText,   
    INT ttiIcon = TTI_NONE);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pEditBalloonTip`|Ponteiro para uma [EDITBALLOONTIP](http://msdn.microsoft.com/library/windows/desktop/bb775466) estrutura que descreve a dica de balão.|  
|[in] `lpszTitle`|Ponteiro para uma cadeia de caracteres Unicode que contém o título da dica de balão.|  
|[in] `lpszText`|Ponteiro para uma cadeia de caracteres Unicode que contém o texto da dica de balão.|  
|[in] `ttiIcon`|Um `INT` que especifica o tipo de ícone a ser associado com a dica de balão. O valor padrão é `TTI_NONE`. Para obter mais informações, consulte o `ttiIcon` membro do [EDITBALLOONTIP](http://msdn.microsoft.com/library/windows/desktop/bb775466) estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Essa função envia o [EM_SHOWBALLOONTIP](http://msdn.microsoft.com/library/windows/desktop/bb761668) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Para obter mais informações, consulte o [Edit_ShowBalloonTip](http://msdn.microsoft.com/library/windows/desktop/bb761707) macro.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define uma variável, `m_cedit`, que é usado para acessar o controle de edição atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CEdit_s1 n º&1;](../../mfc/reference/codesnippet/cpp/cedit-class_25.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir exibe uma dica de balão para um controle de edição. O [CEdit::ShowBalloonTip](#showballoontip) método Especifica um texto da dica de balão e de título.  
  
 [!code-cpp[NVC_MFC_CEdit_s1 n º&3;](../../mfc/reference/codesnippet/cpp/cedit-class_26.cpp)]  
  
##  <a name="undo"></a>CEdit::Undo  
 Chame essa função para desfazer a última operação de controle de edição.  
  
```  
BOOL Undo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Para um controle de edição de linha única, o valor de retorno é sempre zero. Para um controle de edição de várias linhas, o valor de retorno é diferente de zero se a operação de desfazer for bem-sucedida, ou 0 se a operação de desfazer falhar.  
  
### <a name="remarks"></a>Comentários  
 Uma operação de desfazer também pode ser desfeita. Por exemplo, você pode restaurar o texto excluído com a primeira chamada para **desfazer**. Como não há nenhuma operação de edição intermediários, você pode remover o texto novamente com uma segunda chamada para **desfazer**.  
  
 Para obter mais informações, consulte [EM_UNDO](http://msdn.microsoft.com/library/windows/desktop/bb761670) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFC_CEdit](../../mfc/reference/codesnippet/cpp/cedit-class_27.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)   
 [CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](cwnd-class.md)   
 [Classe CButton](cbutton-class.md)   
 [Classe CComboBox](ccombobox-class.md)   
 [Classe CListBox](clistbox-class.md)   
 [Classe CScrollBar](cscrollbar-class.md)   
 [Classe CStatic](cstatic-class.md)   
 [Classe CDialog](cdialog-class.md)

