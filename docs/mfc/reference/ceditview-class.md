---
title: Classe CEditView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CEditView
- AFXEXT/CEditView
- AFXEXT/CEditView::CEditView
- AFXEXT/CEditView::FindText
- AFXEXT/CEditView::GetBufferLength
- AFXEXT/CEditView::GetEditCtrl
- AFXEXT/CEditView::GetPrinterFont
- AFXEXT/CEditView::GetSelectedText
- AFXEXT/CEditView::LockBuffer
- AFXEXT/CEditView::PrintInsideRect
- AFXEXT/CEditView::SerializeRaw
- AFXEXT/CEditView::SetPrinterFont
- AFXEXT/CEditView::SetTabStops
- AFXEXT/CEditView::UnlockBuffer
- AFXEXT/CEditView::OnFindNext
- AFXEXT/CEditView::OnReplaceAll
- AFXEXT/CEditView::OnReplaceSel
- AFXEXT/CEditView::OnTextNotFound
- AFXEXT/CEditView::dwStyleDefault
dev_langs:
- C++
helpviewer_keywords:
- text editors, CEditView class
- text editors
- edit controls, classes
- views, classes
- CEditView class
ms.assetid: bf38255c-fcbe-450c-95b2-3c5e35f86c37
caps.latest.revision: 25
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 688a6c0e871a9456b85a8ed02ce43d7fa9ca8180
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ceditview-class"></a>Classe CEditView
Um tipo de classe de exibição que fornece a funcionalidade de uma janela de controle de edição e pode ser usado para implementar a funcionalidade do editor de texto simples.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CEditView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEditView::CEditView](#ceditview)|Constrói um objeto do tipo `CEditView`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEditView::FindText](#findtext)|Pesquisa uma cadeia de caracteres dentro do texto.|  
|[CEditView::GetBufferLength](#getbufferlength)|Obtém o comprimento do buffer de caracteres.|  
|[CEditView::GetEditCtrl](#geteditctrl)|Fornece acesso para o `CEdit` parte de uma `CEditView` objeto (controle de edição do Windows).|  
|[CEditView::GetPrinterFont](#getprinterfont)|Recupera a fonte da impressora atual.|  
|[CEditView::GetSelectedText](#getselectedtext)|Recupera a seleção de texto atual.|  
|[CEditView::LockBuffer](#lockbuffer)|Bloqueia o buffer.|  
|[CEditView::PrintInsideRect](#printinsiderect)|Processa o texto dentro de um retângulo determinado.|  
|[CEditView::SerializeRaw](#serializeraw)|Serializa um `CEditView` objeto no disco como texto não processado.|  
|[CEditView::SetPrinterFont](#setprinterfont)|Define uma nova fonte de impressora.|  
|[CEditView::SetTabStops](#settabstops)|Conjuntos de tabulação para exibição na tela e impressão.|  
|[CEditView::UnlockBuffer](#unlockbuffer)|Desbloqueia o buffer.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEditView::OnFindNext](#onfindnext)|Localiza a próxima ocorrência de uma cadeia de caracteres de texto.|  
|[CEditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de uma determinada cadeia de caracteres com uma nova cadeia de caracteres.|  
|[CEditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|  
|[CEditView::OnTextNotFound](#ontextnotfound)|Chamado quando uma operação de localização não corresponde a qualquer texto adicional.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CEditView::dwStyleDefault](#dwstyledefault)|Estilo de objetos do tipo padrão **CEditView.**|  
  
## <a name="remarks"></a>Comentários  
 O `CEditView` classe fornece as seguintes funções adicionais:  
  
-   Imprima.  
  
-   Localizar e substituir.  
  
 Como classe `CEditView` é um derivado da classe `CView`, objetos da classe `CEditView` pode ser usado com documentos e modelos de documento.  
  
 Cada `CEditView` texto do controle é mantido em seu próprio objeto de memória global. O aplicativo pode ter qualquer número de `CEditView` objetos.  
  
 Criar objetos do tipo `CEditView` uma janela de edição com a funcionalidade adicionada listada acima, ou se desejar a funcionalidade do editor de texto simples. Um `CEditView` objeto pode ocupar toda a área cliente de uma janela. Derivar suas próprias classes de `CEditView` para adicionar ou modificar a funcionalidade básica ou declarar classes que podem ser adicionados a um modelo de documento.  
  
 A implementação padrão da classe `CEditView` lida com os seguintes comandos: **ID_EDIT_SELECT_ALL**, **ID_EDIT_FIND**, **ID_EDIT_REPLACE**, **ID_EDIT_REPEAT**, e **ID_FILE_PRINT**.  
  
 O limite de caracteres padrão de `CEditView` é (1024 \* 1024-1 = 1048575). Isso pode ser alterado, chamando o **EM_LIMITTEXT** controle de edição de função de subjacente. No entanto, os limites são diferentes dependendo do sistema operacional e o tipo de editar controle (única ou várias linhas). Para obter mais informações sobre esses limites, consulte [EM_LIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb761607).  
  
 Para alterar esse limite em seu controle, substitua o `OnCreate()` funcionar para o `CEditView` de classe e insira a seguinte linha de código:  
  
 [!code-cpp[NVC_MFCDocView&#65;](../../mfc/codesnippet/cpp/ceditview-class_1.cpp)]  
  
 Objetos do tipo `CEditView` (ou de tipos derivados de `CEditView`) têm as seguintes limitações:  
  
- `CEditView`não implementa true que você vê é o que você tem a edição (WYSIWYG). Onde há uma escolha entre legibilidade na tela e impressão correspondente `CEditView` aceita para a leitura na tela.  
  
- `CEditView`pode exibir texto em apenas uma única fonte. Não há suporte para nenhuma formatação de caractere especial. Consulte a classe [CRichEditView](../../mfc/reference/cricheditview-class.md) para mais recursos.  
  
-   A quantidade de texto um `CEditView` pode conter é limitado. Os limites são os mesmos para o `CEdit` controle.  
  
 Para obter mais informações sobre `CEditView`, consulte [derivado exibição Classes disponíveis no MFC](../../mfc/derived-view-classes-available-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CEditView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="ceditview"></a>CEditView::CEditView  
 Constrói um objeto do tipo `CEditView`.  
  
```  
CEditView();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar o objeto, você deve chamar o [CWnd::Create](../../mfc/reference/cwnd-class.md#create) funcionar antes do controle de edição é usado. Se você derivar uma classe de `CEditView` e adicione-a usando o modelo `CWinApp::AddDocTemplate`, a estrutura chama esse construtor dois e o **criar** função.  
  
##  <a name="dwstyledefault"></a>CEditView::dwStyleDefault  
 Contém o estilo de padrão de `CEditView` objeto.  
  
```  
static const DWORD dwStyleDefault;  
```  
  
### <a name="remarks"></a>Comentários  
 Passar este membro estático como o `dwStyle` parâmetro o **criar** função para obter o estilo padrão para o `CEditView` objeto.  
  
##  <a name="findtext"></a>CEditView::FindText  
 Chamar o `FindText` função para pesquisar o `CEditView` buffer de texto do objeto.  
  
```  
BOOL FindText(
    LPCTSTR lpszFind,  
    BOOL bNext = TRUE,  
    BOOL bCase = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser localizado.  
  
 `bNext`  
 Especifica a direção da pesquisa. Se **TRUE**, a direção da pesquisa é o final do buffer. Se **FALSE**, a direção da pesquisa é o início do buffer.  
  
 `bCase`  
 Especifica se a pesquisa diferencia maiusculas de minúsculas. Se **TRUE**, a pesquisa diferencia maiusculas de minúsculas. Se **FALSE**, a pesquisa não diferencia maiusculas de minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o texto de pesquisa for encontrado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função pesquisa o texto no buffer de busca do texto especificado por `lpszFind`, começando na seleção atual, na direção especificada por `bNext`e com maiusculas e minúsculas especificado por `bCase`. Se o texto for encontrado, ele define a seleção para o texto localizado e retorna um valor diferente de zero. Se o texto não for encontrado, a função retornará 0.  
  
 Você normalmente não precisa chamar o `FindText` função a menos que você substitua `OnFindNext`, que chama `FindText`.  
  
##  <a name="getbufferlength"></a>CEditView::GetBufferLength  
 Chame essa função de membro para obter o número de caracteres atualmente no buffer do controle de edição, não incluindo o terminador nulo.  
  
```  
UINT GetBufferLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres no buffer.  
  
##  <a name="geteditctrl"></a>CEditView::GetEditCtrl  
 Chamar `GetEditCtrl` para obter uma referência para o controle de edição usada pelo modo de exibição editar.  
  
```  
CEdit& GetEditCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um objeto `CEdit`.  
  
### <a name="remarks"></a>Comentários  
 Este controle é do tipo [CEdit](../../mfc/reference/cedit-class.md), portanto, você pode manipular o controle de edição do Windows diretamente usando o `CEdit` funções de membro.  
  
> [!CAUTION]
>  Usando o `CEdit` pode alterar o estado do Windows subjacente controle de edição do objeto. Por exemplo, você não deve alterar as configurações da guia usando o [CEdit::SetTabStops](../../mfc/reference/cedit-class.md#settabstops) funcionar porque `CEditView` armazena essas configurações para uso no controle de edição e na impressão. Em vez disso, use [CEditView::SetTabStops](#settabstops).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#66;](../../mfc/codesnippet/cpp/ceditview-class_2.cpp)]  
  
##  <a name="getprinterfont"></a>CEditView::GetPrinterFont  
 Chamar `GetPrinterFont` para obter um ponteiro para um [CFont](../../mfc/reference/cfont-class.md) objeto que descreve a fonte da impressora atual.  
  
```  
CFont* GetPrinterFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CFont` objeto que especifica a fonte de impressora atual. **Nulo** se a fonte da impressora não foi definida. O ponteiro pode ser temporário e não deve ser armazenado para uso posterior.  
  
### <a name="remarks"></a>Comentários  
 Se a fonte da impressora não foi definida, o padrão de impressão de comportamento da `CEditView` classe é imprimir usando a mesma fonte usada para exibição.  
  
 Use esta função para determinar a fonte atual da impressora. Se não for a fonte da impressora desejada, use [CEditView::SetPrinterFont](#setprinterfont) para alterá-lo.  
  
##  <a name="getselectedtext"></a>CEditView::GetSelectedText  
 Chamar `GetSelectedText` para copiar o texto selecionado em uma `CString` objeto até o fim da seleção ou o caractere que precede o primeiro caractere de retorno de carro na seleção.  
  
```  
void GetSelectedText(CString& strResult) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `strResult`  
 Uma referência para o `CString` objeto que receberá o texto selecionado.  
  
##  <a name="lockbuffer"></a>CEditView::LockBuffer  
 Chame essa função de membro para obter um ponteiro para o buffer. O buffer não deve ser modificado.  
  
```  
LPCTSTR LockBuffer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer do controle de edição.  
  
##  <a name="onfindnext"></a>CEditView::OnFindNext  
 Pesquisa de texto no buffer de busca do texto especificado por `lpszFind`, na direção especificada por `bNext`, diferenciando maiusculas e minúsculas especificada por `bCase`.  
  
```  
virtual void OnFindNext(
    LPCTSTR lpszFind,  
    BOOL bNext,  
    BOOL bCase);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser localizado.  
  
 `bNext`  
 Especifica a direção da pesquisa. Se **TRUE**, a direção da pesquisa é o final do buffer. Se **FALSE**, a direção da pesquisa é o início do buffer.  
  
 `bCase`  
 Especifica se a pesquisa diferencia maiusculas de minúsculas. Se **TRUE**, a pesquisa diferencia maiusculas de minúsculas. Se **FALSE**, a pesquisa não diferencia maiusculas de minúsculas.  
  
### <a name="remarks"></a>Comentários  
 A pesquisa começará no início da seleção atual e é realizada por meio de uma chamada para [FindText](#findtext). Na implementação do padrão, `OnFindNext` chamadas [OnTextNotFound](#ontextnotfound) se o texto não for encontrado.  
  
 Substituir `OnFindNext` para alterar a forma como um `CEditView`-objeto derivado pesquisas de texto. `CEditView`chamadas `OnFindNext` quando o usuário escolhe o botão Localizar próxima na caixa de diálogo Localizar padrão.  
  
##  <a name="onreplaceall"></a>CEditView::OnReplaceAll  
 `CEditView`chamadas `OnReplaceAll` quando o usuário seleciona o botão Substituir tudo na caixa de diálogo Substituir padrão.  
  
```  
virtual void OnReplaceAll(
    LPCTSTR lpszFind,  
    LPCTSTR lpszReplace,  
    BOOL bCase);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser localizado.  
  
 `lpszReplace`  
 O texto que substituirá o texto de pesquisa.  
  
 `bCase`  
 Especifica se a pesquisa diferencia maiusculas de minúsculas. Se **TRUE**, a pesquisa diferencia maiusculas de minúsculas. Se **FALSE**, a pesquisa não diferencia maiusculas de minúsculas.  
  
### <a name="remarks"></a>Comentários  
 `OnReplaceAll`pesquisa de texto no buffer de busca do texto especificado por `lpszFind`, diferenciando maiusculas e minúsculas especificada por `bCase`. A pesquisa começará no início da seleção atual. Cada vez que o texto de pesquisa for encontrado, essa função substitui essa ocorrência do texto com o texto especificado por `lpszReplace`. A pesquisa é realizada por meio de uma chamada para [FindText](#findtext). Na implementação do padrão, [OnTextNotFound](#ontextnotfound) é chamado se o texto não foi encontrado.  
  
 Se a seleção atual não corresponder `lpszFind`, a seleção é atualizada para a primeira ocorrência do texto especificado por `lpszFind` e uma substituição não será executada. Isso permite ao usuário confirmar que isso é o que desejam fazer quando a seleção não coincide com o texto a ser substituído.  
  
 Substituir `OnReplaceAll` para alterar a forma como um `CEditView`-objeto derivado substitui o texto.  
  
##  <a name="onreplacesel"></a>CEditView::OnReplaceSel  
 `CEditView`chamadas `OnReplaceSel` quando o usuário seleciona o botão Substituir na caixa de diálogo Substituir padrão.  
  
```  
virtual void OnReplaceSel(
    LPCTSTR lpszFind,  
    BOOL bNext,  
    BOOL bCase,  
    LPCTSTR lpszReplace);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser localizado.  
  
 `bNext`  
 Especifica a direção da pesquisa. Se **TRUE**, a direção da pesquisa é o final do buffer. Se **FALSE**, a direção da pesquisa é o início do buffer.  
  
 `bCase`  
 Especifica se a pesquisa diferencia maiusculas de minúsculas. Se **TRUE**, a pesquisa diferencia maiusculas de minúsculas. Se **FALSE**, a pesquisa não diferencia maiusculas de minúsculas.  
  
 `lpszReplace`  
 O texto para substituir o texto localizado.  
  
### <a name="remarks"></a>Comentários  
 Depois de substituir a seleção, essa função pesquisa o texto no buffer para a próxima ocorrência do texto especificado por `lpszFind`, na direção especificada por `bNext`, diferenciando maiusculas e minúsculas especificada por `bCase`. A pesquisa é realizada por meio de uma chamada para [FindText](#findtext). Se o texto não for encontrado, [OnTextNotFound](#ontextnotfound) é chamado.  
  
 Substituir `OnReplaceSel` para alterar a forma como um `CEditView`-objeto derivada substitui o texto selecionado.  
  
##  <a name="ontextnotfound"></a>CEditView::OnTextNotFound  
 Substituir essa função para alterar a implementação padrão, que chama a função do Windows **MessageBeep**.  
  
```  
virtual void OnTextNotFound(LPCTSTR lpszFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser localizado.  
  
##  <a name="printinsiderect"></a>CEditView::PrintInsideRect  
 Chamar `PrintInsideRect` para imprimir o texto no retângulo especificado por *rectLayout*.  
  
```  
UINT PrintInsideRect(
    CDC *pDC,  
    RECT& rectLayout,  
    UINT nIndexStart,  
    UINT nIndexStop);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para o contexto de dispositivo da impressora.  
  
 *rectLayout*  
 Referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [estrutura RECT](../../mfc/reference/rect-structure1.md) especificando o retângulo na qual o texto é renderizado.  
  
 `nIndexStart`  
 Índice dentro do buffer do primeiro caractere a ser processado.  
  
 `nIndexStop`  
 Índice dentro do buffer do caractere após o último caractere a ser processado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do próximo caractere a ser impressa (ou seja, o caractere após o último caractere processado).  
  
### <a name="remarks"></a>Comentários  
 Se o `CEditView` controle não tem o estilo **ES_AUTOHSCROLL**, texto é quebrado dentro do retângulo de renderização. Se o controle tem o estilo **ES_AUTOHSCROLL**, o texto será recortado na borda direita do retângulo.  
  
 O **rect.bottom** elemento o *rectLayout* objeto é alterado para que a parte do retângulo original que está ocupado pelo texto de definir dimensões do retângulo.  
  
##  <a name="serializeraw"></a>CEditView::SerializeRaw  
 Chamar `SerializeRaw` ter um `CArchive` objeto ler ou gravar o texto no `CEditView` objeto para um arquivo de texto.  
  
```  
void SerializeRaw(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 Referência para o `CArchive` objeto que armazena o texto serializado.  
  
### <a name="remarks"></a>Comentários  
 `SerializeRaw`é diferente de `CEditView`da implementação interna do `Serialize` que lê e grava apenas o texto sem precedente dados descrição do objeto.  
  
##  <a name="setprinterfont"></a>CEditView::SetPrinterFont  
 Chamar `SetPrinterFont` para definir a fonte de impressora para a fonte especificada pela `pFont`.  
  
```  
void SetPrinterFont(CFont* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFont`  
 Um ponteiro para um objeto do tipo `CFont`. Se **nulo**, a fonte usada para impressão é baseada na fonte do vídeo.  
  
### <a name="remarks"></a>Comentários  
 Se desejar que o modo de exibição sempre usar uma fonte específica para impressão, incluir uma chamada para `SetPrinterFont` em sua classe `OnPreparePrinting` função. Essa função virtual é chamada antes de imprimir, para que a alteração de fonte ocorre antes do conteúdo da exibição é impressos.  
  
##  <a name="settabstops"></a>CEditView::SetTabStops  
 Chame essa função para definir as paradas de tabulação usadas para exibição e impressão.  
  
```  
void SetTabStops(int nTabStops);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTabStops`  
 Largura de cada parada de tabulação, em unidades de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Há suporte para apenas uma única largura de parada de tabulação. ( `CEdit` objetos oferecem suporte a várias larguras de guia.) Larguras estão em unidades de caixa de diálogo, que é igual a um quarto da largura do caractere médio (com base em letras maiusculos e minúsculos somente caracteres alfabéticos) da fonte usada no momento da impressão ou exibição. Você não deve usar `CEdit::SetTabStops` porque `CEditView` deve armazenar em cache o valor de parada de tabulação.  
  
 Essa função modifica somente as guias do objeto para o qual ele é chamado. Para alterar a guia para para cada `CEditView` de objeto em seu aplicativo, chamar cada objeto `SetTabStops` função.  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código define as paradas de tabulação no controle para cada caractere quarto medindo cuidadosamente a fonte que usa o controle.  
  
 [!code-cpp[NVC_MFCDocView&#67;](../../mfc/codesnippet/cpp/ceditview-class_3.cpp)]  
  
##  <a name="unlockbuffer"></a>CEditView::UnlockBuffer  
 Chame essa função de membro para desbloquear o buffer.  
  
```  
void UnlockBuffer() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Chamar `UnlockBuffer` depois de terminar de usar o ponteiro retornado por [LockBuffer](#lockbuffer).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC SUPERPAD](../../visual-cpp-samples.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

