---
title: Classe CMFCPropertyGridProperty | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCPropertyGridProperty
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyGridProperty class
ms.assetid: 36f3fabe-0efe-468b-8a0b-5a7956db38a2
caps.latest.revision: 35
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
ms.openlocfilehash: e0a8dfc9d4475947e65c827d7ff9a37a429b7feb
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcpropertygridproperty-class"></a>Classe CMFCPropertyGridProperty
Um `CMFCPropertyGridProperty` objeto representa um item de lista em um controle de lista de propriedade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPropertyGridProperty : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridProperty::CMFCPropertyGridProperty](#cmfcpropertygridproperty)|Constrói um objeto `CMFCPropertyGridProperty`.|  
|`CMFCPropertyGridProperty::~CMFCPropertyGridProperty`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridProperty::AddOption](#addoption)|Adiciona um novo item de lista a um controle de lista de propriedade.|  
|[CMFCPropertyGridProperty::AddSubItem](#addsubitem)|Adiciona um item filho a uma propriedade.|  
|[CMFCPropertyGridProperty::AdjustButtonRect](#adjustbuttonrect)|Chamado pelo controle de lista de propriedade pai para informar uma propriedade para redimensionar o retângulo delimitador de um botão incorporado.|  
|[CMFCPropertyGridProperty::AdjustInPlaceEditRect](#adjustinplaceeditrect)|Recupera os limites da caixa de texto e controle de botão de rotação opcionais que são usados para definir um valor de propriedade.|  
|[CMFCPropertyGridProperty::AllowEdit](#allowedit)|Torna a propriedade editável ou somente leitura.|  
|[CMFCPropertyGridProperty::CreateInPlaceEdit](#createinplaceedit)|Chamado pela estrutura para criar um controle editável de uma propriedade.|  
|[CMFCPropertyGridProperty::CreateSpinControl](#createspincontrol)|Chamado pela estrutura para criar um controle de botão de rotação editável.|  
|[CMFCPropertyGridProperty::Enable](#enable)|Habilita ou desabilita uma propriedade.|  
|[CMFCPropertyGridProperty::EnableSpinControl](#enablespincontrol)|Habilita ou desabilita um controle de botão de rotação que é usado para modificar um valor de propriedade.|  
|[CMFCPropertyGridProperty::Expand](#expand)|Expande ou recolhe uma propriedade que contém subpropriedades.|  
|[CMFCPropertyGridProperty::FormatProperty](#formatproperty)|Formata a representação de um valor de propriedade.|  
|[CMFCPropertyGridProperty::GetData](#getdata)|Recupera um `DWORD` valor que está associado uma propriedade.|  
|[CMFCPropertyGridProperty::GetDescription](#getdescription)|Recupera uma descrição da propriedade.|  
|[CMFCPropertyGridProperty::GetExpandedSubItems](#getexpandedsubitems)|Recupera o número de itens de subpropriedades expandidos.|  
|[CMFCPropertyGridProperty::GetHierarchyLevel](#gethierarchylevel)|Retorna o índice baseado em zero do nível da hierarquia da propriedade.|  
|[CMFCPropertyGridProperty::GetName](#getname)|Recupera o nome da propriedade.|  
|[CMFCPropertyGridProperty::GetNameTooltip](#getnametooltip)|Chamado pela estrutura para exibir o nome da propriedade em uma dica de ferramenta.|  
|[CMFCPropertyGridProperty::GetOption](#getoption)|Recupera o texto da opção que é especificado por um índice.|  
|[CMFCPropertyGridProperty::GetOptionCount](#getoptioncount)|Recupera o número de opções que pertencem a uma propriedade.|  
|[CMFCPropertyGridProperty::GetOriginalValue](#getoriginalvalue)|Recupera o valor inicial da propriedade atual.|  
|[CMFCPropertyGridProperty::GetParent](#getparent)|Recupera um ponteiro para uma propriedade pai.|  
|[CMFCPropertyGridProperty::GetRect](#getrect)|Recupera o retângulo delimitador de uma propriedade.|  
|[CMFCPropertyGridProperty::GetSubItem](#getsubitem)|Recupera uma propriedade subpropriedades identificada por um índice baseado em zero.|  
|[CMFCPropertyGridProperty::GetSubItemsCount](#getsubitemscount)|Recupera o número de itens de subpastas.|  
|`CMFCPropertyGridProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCPropertyGridProperty::GetValue](#getvalue)|Recupera um valor de propriedade.|  
|[CMFCPropertyGridProperty::GetValueTooltip](#getvaluetooltip)|Chamado pela estrutura para recuperar a representação de texto do valor da propriedade que é exibido em uma dica de ferramenta.|  
|[CMFCPropertyGridProperty::HitTest](#hittest)|Aponta para o objeto de propriedade que corresponde ao item de lista de propriedade que corresponde a um ponto.|  
|[CMFCPropertyGridProperty::IsAllowEdit](#isallowedit)|Indica se uma propriedade é editável.|  
|[CMFCPropertyGridProperty::IsEnabled](#isenabled)|Indica se uma propriedade está habilitada ou desabilitada.|  
|[CMFCPropertyGridProperty::IsExpanded](#isexpanded)|Indica se uma propriedade é expandida ou recolhida.|  
|[CMFCPropertyGridProperty::IsGroup](#isgroup)|Indica se a propriedade atual representa um grupo.|  
|[CMFCPropertyGridProperty::IsInPlaceEditing](#isinplaceediting)|Indica se a propriedade atual é editável.|  
|[CMFCPropertyGridProperty::IsModified](#ismodified)|Indica se a propriedade atual é modificada.|  
|[CMFCPropertyGridProperty::IsParentExpanded](#isparentexpanded)|Indica se os pais da propriedade atual são expandidos.|  
|[CMFCPropertyGridProperty::IsSelected](#isselected)|Indica se a propriedade atual está selecionada.|  
|[CMFCPropertyGridProperty::IsVisible](#isvisible)|Indica se a propriedade atual está visível.|  
|[CMFCPropertyGridProperty::OnClickButton](#onclickbutton)|Chamado pela estrutura quando o usuário clica em um botão que está contido em uma propriedade.|  
|[CMFCPropertyGridProperty::OnClickName](#onclickname)|Chamado por um controle de lista de propriedade pai quando um usuário clica no campo nome de uma propriedade.|  
|[CMFCPropertyGridProperty::OnClickValue](#onclickvalue)|Chamado por um controle de lista de propriedade pai quando um usuário clica no campo valor de uma propriedade.|  
|[CMFCPropertyGridProperty::OnCloseCombo](#onclosecombo)|Chamado pela estrutura quando uma caixa de combinação que está contida em uma propriedade é fechada.|  
|[CMFCPropertyGridProperty::OnDblClk](#ondblclk)|Chamado pela estrutura quando o usuário clicar duas vezes uma propriedade.|  
|[CMFCPropertyGridProperty::OnDrawButton](#ondrawbutton)|Chamado pela estrutura para desenhar um botão que está contido em uma propriedade.|  
|[CMFCPropertyGridProperty::OnDrawDescription](#ondrawdescription)|Chamado pela estrutura para exibir a descrição da propriedade.|  
|[CMFCPropertyGridProperty::OnDrawExpandBox](#ondrawexpandbox)|Chamado pela estrutura para desenhar um controle de caixa de expansão perto de uma propriedade que contém subpropriedades.|  
|[CMFCPropertyGridProperty::OnDrawName](#ondrawname)|Chamado pela estrutura para exibir o nome da propriedade.|  
|[CMFCPropertyGridProperty::OnDrawValue](#ondrawvalue)|Chamado pela estrutura para exibir o valor da propriedade.|  
|[CMFCPropertyGridProperty::OnEdit](#onedit)|Chamado pela estrutura quando o usuário está prestes a modificar um valor da propriedade.|  
|[CMFCPropertyGridProperty::OnEndEdit](#onendedit)|Chamado pela estrutura quando o usuário modificando um valor de propriedade.|  
|[CMFCPropertyGridProperty::OnKillSelection](#onkillselection)||  
|[CMFCPropertyGridProperty::OnPosSizeChanged](#onpossizechanged)||  
|[CMFCPropertyGridProperty::OnRClickName](#onrclickname)|Chamado pela estrutura quando o usuário clica no botão direito do mouse na área de nome de propriedade.|  
|[CMFCPropertyGridProperty::OnRClickValue](#onrclickvalue)|Chamado pela estrutura quando o usuário clica no botão direito do mouse na área de valor de propriedade.|  
|[CMFCPropertyGridProperty::OnSelectCombo](#onselectcombo)|Chamado pela estrutura quando o usuário seleciona um item da caixa de combinação editável.|  
|[CMFCPropertyGridProperty::OnSetCursor](#onsetcursor)|Chamado pela estrutura quando o ponteiro do mouse se move para um item de propriedade.|  
|[CMFCPropertyGridProperty::OnSetSelection](#onsetselection)||  
|[CMFCPropertyGridProperty::OnUpdateValue](#onupdatevalue)|Chamado pela estrutura quando o valor de uma propriedade editável é alterado.|  
|[CMFCPropertyGridProperty::PushChar](#pushchar)|Chamado a partir do controle de lista de propriedade quando a propriedade for selecionada e o usuário insere um caractere de nova.|  
|[CMFCPropertyGridProperty::Redraw](#redraw)|Redesenha a propriedade.|  
|[CMFCPropertyGridProperty::RemoveAllOptions](#removealloptions)|Remove todas as opções (itens) de uma propriedade.|  
|[CMFCPropertyGridProperty::RemoveSubItem](#removesubitem)|Remove o item especificado de subpropriedades.|  
|[CMFCPropertyGridProperty::ResetOriginalValue](#resetoriginalvalue)|Restaura o valor original de uma propriedade editada.|  
|[CMFCPropertyGridProperty::SetData](#setdata)|Associa um `DWORD` valor com uma propriedade.|  
|[CMFCPropertyGridProperty::SetDescription](#setdescription)|Especifica o texto que descreve a propriedade atual.|  
|[CMFCPropertyGridProperty::SetName](#setname)|Define o nome de uma propriedade.|  
|[CMFCPropertyGridProperty::SetOriginalValue](#setoriginalvalue)|Define o valor original de uma propriedade editável.|  
|[CMFCPropertyGridProperty::SetValue](#setvalue)|Define o valor de uma propriedade de grade de propriedade.|  
|[CMFCPropertyGridProperty::Show](#show)|Mostra ou oculta uma propriedade.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridProperty::CreateCombo](#createcombo)|Chamado pela estrutura para adicionar uma caixa de combinação a uma propriedade.|  
|[CMFCPropertyGridProperty::HasButton](#hasbutton)|Indica se uma propriedade contém um botão.|  
|[CMFCPropertyGridProperty::Init](#init)|Chamado pela estrutura para inicializar um objeto de propriedade.|  
|[CMFCPropertyGridProperty::IsSubItem](#issubitem)|Indica se a propriedade especificada é um item de subpropriedades da propriedade atual.|  
|[CMFCPropertyGridProperty::IsValueChanged](#isvaluechanged)|Indica se o valor da propriedade atual foi alterado.|  
|[CMFCPropertyGridProperty::OnCtlColor](#onctlcolor)|Chamado pela estrutura quando ele deve recuperar um pincel para preencher a cor de plano de fundo de uma propriedade.|  
|[CMFCPropertyGridProperty::OnDestroyWindow](#ondestroywindow)|Chamado pela estrutura quando uma propriedade é destruída ou quando a edição é concluída.|  
|[CMFCPropertyGridProperty::OnKillFocus](#onkillfocus)|Chamado pela estrutura quando a propriedade perde o foco de entrada.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridProperty::m_strFormatDouble](#m_strformatdouble)|Cadeia de caracteres de formato para um valor do tipo double.|  
|[CMFCPropertyGridProperty::m_strFormatFloat](#m_strformatfloat)|Cadeia de caracteres de formato para um valor de tipo flutuante.|  
|[CMFCPropertyGridProperty::m_strFormatLong](#m_strformatlong)|Cadeia de caracteres para um valor do tipo de formato longo.|  
|[CMFCPropertyGridProperty::m_strFormatShort](#m_strformatshort)|Cadeia de caracteres de formato para um valor do tipo curto.|  
  
## <a name="remarks"></a>Comentários  
 Use um `CMFCPropertyGridProperty` objeto para representar uma propriedade, o que você adicionar a um controle de lista de propriedade. Para obter mais informações, consulte [CMFCPropertyGridCtrl classe](../../mfc/reference/cmfcpropertygridctrl-class.md).  
  
 Um objeto de propriedade pode representar tipos de dados como cadeias de caracteres, datas e valores booleanos ou inteiro. Ele pode conter propriedades filho, ou ele pode conter um controle como uma caixa de combinação ou um controle de botão.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCPropertyGridProperty` objeto. O exemplo também demonstra como usar vários métodos no `CMFCPropertyGridProperty` classe para adicionar uma opção, adicione um subitem, habilitar uma propriedade e mostrar uma propriedade. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls&#27;](../../mfc/reference/codesnippet/cpp/cmfcpropertygridproperty-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
##  <a name="a-nameaddoptiona--cmfcpropertygridpropertyaddoption"></a><a name="addoption"></a>CMFCPropertyGridProperty::AddOption  
 Adiciona um novo item de lista a um controle de lista de propriedade.  
  
```  
BOOL AddOption(
    LPCTSTR lpszOption,  
    BOOL bInsertUnique=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszOption`  
 O item de lista (opção) para adicionar.  
  
 [in] `bInsertUnique`  
 `TRUE`Para adicionar a lista item somente se ele não existir; Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`, que significa que o item de lista é adicionado. Caso contrário, `FALSE`, que significa que o item de lista não é adicionado porque o `bInsertUnique` parâmetro é `TRUE` e lista o item especificado pelo `lpszOption` parâmetro já existe.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameaddsubitema--cmfcpropertygridpropertyaddsubitem"></a><a name="addsubitem"></a>CMFCPropertyGridProperty::AddSubItem  
 Adiciona um item filho a uma propriedade.  
  
```  
BOOL AddSubItem(CMFCPropertyGridProperty* pProp);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pProp`  
 Ponteiro para uma propriedade a ser adicionada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade especificada é adicionada com êxito como uma propriedade filho. `FALSE`Se a propriedade não for adicionada porque ele já está na propriedade pai.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para criar uma lista hierárquica de pai e filho propriedades. Após um filho propriedade é adicionada, a propriedade parent exibe automaticamente um controle de caixa de expansão que é designado por um sinal de adição (+). Quando o usuário clicar no sinal de adição, a propriedade parent expande e exibe todos os itens filhos propriedade.  
  
##  <a name="a-nameadjustbuttonrecta--cmfcpropertygridpropertyadjustbuttonrect"></a><a name="adjustbuttonrect"></a>CMFCPropertyGridProperty::AdjustButtonRect  
 Chamado pelo controle de lista de propriedade pai para informar uma propriedade para redimensionar o retângulo delimitador de um botão incorporado.  
  
```  
virtual void AdjustButtonRect();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método:  
  
-   Ajusta a largura do botão igual a altura do botão mais de 3 pixels.  
  
-   Move o retângulo delimitador do botão para a borda direita da propriedade  
  
-   Desloca o pixel botão 1 abaixo da borda superior da propriedade.  
  
##  <a name="a-nameadjustinplaceeditrecta--cmfcpropertygridpropertyadjustinplaceeditrect"></a><a name="adjustinplaceeditrect"></a>CMFCPropertyGridProperty::AdjustInPlaceEditRect  
 Recupera os limites da caixa de texto e controle de botão de rotação opcionais que são usados para definir um valor de propriedade.  
  
```  
virtual void AdjustInPlaceEditRect(
    CRect& rectEdit,  
    CRect& rectSpin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectEdit`  
 Quando este método retorna, um retângulo que especifica os limites da caixa de texto para o valor da propriedade.  
  
 [out] `rectSpin`  
 Quando este método retorna, um retângulo que especifica os limites do controle de botão de rotação para o valor da propriedade. Ou, se a propriedade não oferece suporte a um botão de rotação, um retângulo vazio.  
  
### <a name="remarks"></a>Comentários  
 A área de valor de uma propriedade consiste em uma caixa de texto e possivelmente um *botão de opção*, como um controle de botão de rotação. Esse método calcula as dimensões do botão de opção e caixa de texto e, em seguida, retorna os valores nos parâmetros especificados.  
  
##  <a name="a-nameallowedita--cmfcpropertygridpropertyallowedit"></a><a name="allowedit"></a>CMFCPropertyGridProperty::AllowEdit  
 Torna a propriedade editável ou somente leitura.  
  
```  
void AllowEdit(BOOL bAllow=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAllow`  
 `TRUE`Para tornar a propriedade editável; `FALSE` para tornar a propriedade somente leitura. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecmfcpropertygridpropertya--cmfcpropertygridpropertycmfcpropertygridproperty"></a><a name="cmfcpropertygridproperty"></a>CMFCPropertyGridProperty::CMFCPropertyGridProperty  
 Constrói um objeto `CMFCPropertyGridProperty`.  
  
```  
CMFCPropertyGridProperty(
    const CString& strGroupName,  
    DWORD_PTR dwData=0,  
    BOOL bIsValueList=FALSE);

 
CMFCPropertyGridProperty(
    const CString& strName,  
    const _variant_t& varValue,  
    LPCTSTR lpszDescr=NULL,  
    DWORD_PTR dwData=0,  
    LPCTSTR lpszEditMask=NULL,  
    LPCTSTR lpszEditTemplate=NULL,  
    LPCTSTR lpszValidChars=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strGroupName`  
 O nome do grupo. A *grupo* é uma coleção de propriedades relacionadas em um controle de grade de propriedade. Se o controle é exibido hierarquicamente, o *nome do grupo* é exibido como um título de categoria na linha acima do grupo.  
  
 [in] `dwData`  
 Dados específicos do aplicativo, como um inteiro ou um ponteiro para outros dados que está associados à propriedade. O valor padrão é 0.  
  
 [in] `strName`  
 O nome da propriedade.  
  
 [in] `varValue`  
 O valor da propriedade.  
  
 [in] `lpszDescr`  
 A descrição da propriedade. O valor padrão é `NULL`.  
  
 [in] `lpszEditMask`  
 A máscara de edição, se a propriedade é um controle de edição mascarada. O valor padrão é `NULL`.  
  
 [in] `lpszEditTemplate`  
 O modelo de edição, se a propriedade é um controle de edição mascarada. O valor padrão é `NULL`.  
  
 [in] `lpszValidChars`  
 Uma lista de caracteres válidos, se a propriedade é um controle de edição mascarada. O valor padrão é `NULL`.  
  
 [in] `bIsValueList`  
 `TRUE`Se a propriedade representa uma lista de valores. `FALSE` se a propriedade representa um único valor. O valor padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreatecomboa--cmfcpropertygridpropertycreatecombo"></a><a name="createcombo"></a>CMFCPropertyGridProperty::CreateCombo  
 Chamado pela estrutura para adicionar uma caixa de combinação a uma propriedade.  
  
```  
virtual CComboBox* CreateCombo(
    CWnd* pWndParent,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParent`  
 Ponteiro para a janela pai da caixa de combinação.  
  
 [in] `rect`  
 O retângulo delimitador da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um novo [CComboBox](../../mfc/reference/ccombobox-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreateinplaceedita--cmfcpropertygridpropertycreateinplaceedit"></a><a name="createinplaceedit"></a>CMFCPropertyGridProperty::CreateInPlaceEdit  
 Chamado pela estrutura para criar um controle editável de uma propriedade.  
  
```  
virtual CWnd* CreateInPlaceEdit(
    CRect rectEdit,  
    BOOL& bDefaultFormat);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectEdit`  
 O retângulo delimitador do controle editável.  
  
 [in] `bDefaultFormat`  
 `TRUE`usar o formato padrão de propriedade para definir o texto do controle editável; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o controle editável se esse método for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Esse método usa os valores da `varValue`, `lpszEditMask`, `lpszEditTemplate`, e `lpszValidChars` os parâmetros especificados no [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md) construtor da classe. Por padrão, esse método oferece suporte a `varValue` tipos variantes. This includes `VT_BSTR`, `VT_R4`, `VT_R8`, `VT_UI1`, `VT_I2`, `VT_INT`, `VT_UINT`, `VT_I4`, `VT_UI2`, `VT_UI4`, and `VT_BOOL`.  
  
 Esse método cria um [CMFCMaskedEdit](../../mfc/reference/cmfcmaskededit-class.md) controlar se um ou mais o `lpszEditMask`, `lpszEditTemplate`, ou `lpszValidChars` são especificados; caso contrário, ele cria um [CEdit](../../mfc/reference/cedit-class.md) controle.  
  
##  <a name="a-namecreatespincontrola--cmfcpropertygridpropertycreatespincontrol"></a><a name="createspincontrol"></a>CMFCPropertyGridProperty::CreateSpinControl  
 Chamado pela estrutura para criar um controle de botão de rotação editável.  
  
```  
virtual CSpinButtonCtrl* CreateSpinControl(CRect rectSpin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectSpin`  
 Um retângulo que define onde o controle de botão de rotação editável é criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um novo [CMFCSpinButtonCtrl](../../mfc/reference/cmfcspinbuttonctrl-class.md) objeto que é convertido como um ponteiro para um [CSpinButtonCtrl](../../mfc/reference/cspinbuttonctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCPropertyGridProperty::EnableSpinControl](#enablespincontrol) método para exibir um controle de botão de rotação editável na extremidade direita da propriedade.  
  
##  <a name="a-nameenablea--cmfcpropertygridpropertyenable"></a><a name="enable"></a>CMFCPropertyGridProperty::Enable  
 Habilita ou desabilita uma propriedade.  
  
```  
void Enable(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a propriedade; `FALSE` para desabilitar a propriedade. Propriedades não respondem ao mouse ou teclado desabilitado. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablespincontrola--cmfcpropertygridpropertyenablespincontrol"></a><a name="enablespincontrol"></a>CMFCPropertyGridProperty::EnableSpinControl  
 Habilita ou desabilita um controle de botão de rotação que é usado para modificar um valor de propriedade.  
  
```  
void EnableSpinControl(
    BOOL bEnable=TRUE,  
    int nMin=0,  
    int nMax=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o controle de botão de rotação; `FALSE` para desabilitar o controle de botão de rotação. O valor padrão é `TRUE`.  
  
 [in] `nMin`  
 O valor mínimo do controle de botão de rotação. O valor padrão é 0.  
  
 [in] `nMax`  
 O valor máximo do controle de botão de rotação. O valor padrão é 0.  
  
### <a name="remarks"></a>Comentários  
 O framework cria automaticamente um controle de botão de rotação quando uma propriedade está prestes a ser editado.  
  
 O tipo de propriedade, que é especificado pelo `varValue` parâmetro o [CMFCPropertyGridProperty::CMFCPropertyGridProperty](#cmfcpropertygridproperty) construtor, deve ser um tipo variant com suporte. Caso contrário, esse método declara no modo de depuração. Os tipos com suporte incluem `VT_INT`, `VT_UINT`, `VT_I2`, `VT_I4`, `VT_UI2`, e `VT_UI4`.  
  
##  <a name="a-nameexpanda--cmfcpropertygridpropertyexpand"></a><a name="expand"></a>CMFCPropertyGridProperty::Expand  
 Expande ou recolhe uma propriedade que contém subpropriedades.  
  
```  
void Expand(BOOL bExpand=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bExpand`  
 `TRUE`para expandir a propriedade; FALSE para recolher a propriedade. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameformatpropertya--cmfcpropertygridpropertyformatproperty"></a><a name="formatproperty"></a>CMFCPropertyGridProperty::FormatProperty  
 Formata a representação de um valor de propriedade.  
  
```  
virtual CString FormatProperty();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A representação de texto do valor da propriedade.  
  
### <a name="remarks"></a>Comentários  
 Este método é chamado pela estrutura antes que o valor da propriedade é exibido.  
  
##  <a name="a-namegetdataa--cmfcpropertygridpropertygetdata"></a><a name="getdata"></a>CMFCPropertyGridProperty::GetData  
 Recupera um `DWORD` valor que está associado uma propriedade.  
  
```  
DWORD_PTR GetData() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor `DWORD`.  
  
### <a name="remarks"></a>Comentários  
 Os dados que são retornados são um valor específico do aplicativo, como um número ou um ponteiro para outros dados. Especifique o valor de dados quando você constrói a propriedade ou quando você chama o [CMFCPropertyGridProperty::SetData](#setdata) método.  
  
##  <a name="a-namegetdescriptiona--cmfcpropertygridpropertygetdescription"></a><a name="getdescription"></a>CMFCPropertyGridProperty::GetDescription  
 Recupera uma descrição da propriedade.  
  
```  
const CString& GetDescription() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres de texto que contém a descrição da propriedade.  
  
### <a name="remarks"></a>Comentários  
 Controle de lista de propriedade também usa este método para exibir a descrição da propriedade.  
  
##  <a name="a-namegetexpandedsubitemsa--cmfcpropertygridpropertygetexpandedsubitems"></a><a name="getexpandedsubitems"></a>CMFCPropertyGridProperty::GetExpandedSubItems  
 Recupera o número de itens de subpropriedades expandidos.  
  
```  
int GetExpandedSubItems(BOOL bIncludeHidden=TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `bIncludeHidden`|`TRUE`para incluir os subelementos ocultos na contagem; Caso contrário, `FALSE`. O valor padrão é `TRUE`.|  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens de subpropriedades expandidos.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegethierarchylevela--cmfcpropertygridpropertygethierarchylevel"></a><a name="gethierarchylevel"></a>CMFCPropertyGridProperty::GetHierarchyLevel  
 Retorna o índice baseado em zero do nível da hierarquia da propriedade.  
  
```  
int GetHierarchyLevel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Nível hierárquico da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetnamea--cmfcpropertygridpropertygetname"></a><a name="getname"></a>CMFCPropertyGridProperty::GetName  
 Recupera o nome da propriedade.  
  
```  
LPCTSTR GetName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma cadeia de caracteres que contém o nome da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetnametooltipa--cmfcpropertygridpropertygetnametooltip"></a><a name="getnametooltip"></a>CMFCPropertyGridProperty::GetNameTooltip  
 Chamado pela estrutura para exibir o nome da propriedade em uma dica de ferramenta.  
  
```  
virtual CString GetNameTooltip();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o nome da propriedade. Por padrão, o valor de retorno é a cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetoptiona--cmfcpropertygridpropertygetoption"></a><a name="getoption"></a>CMFCPropertyGridProperty::GetOption  
 Recupera o texto da opção que é especificado por um índice.  
  
```  
LPCTSTR GetOption(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice baseado em zero do item de lista da propriedade (opção) para recuperar.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma cadeia de caracteres que contém o texto da opção.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetoptioncounta--cmfcpropertygridpropertygetoptioncount"></a><a name="getoptioncount"></a>CMFCPropertyGridProperty::GetOptionCount  
 Recupera o número de opções que pertencem a uma propriedade.  
  
```  
int GetOptionCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens de lista de propriedade (Opções) que estão contidos no controle de propriedade.  
  
### <a name="remarks"></a>Comentários  
 Chamar o [CMFCPropertyGridProperty::AddOption](#addoption) método para adicionar itens à lista de propriedades. Chamar o [CMFCPropertyGridProperty::RemoveAllOptions](#removealloptions) método para remover todos os itens.  
  
##  <a name="a-namegetoriginalvaluea--cmfcpropertygridpropertygetoriginalvalue"></a><a name="getoriginalvalue"></a>CMFCPropertyGridProperty::GetOriginalValue  
 Recupera o valor inicial da propriedade atual.  
  
```  
const COleVariant& GetOriginalValue() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor original da propriedade atual.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para desfazer o efeito de uma operação de edição que altera o valor da propriedade atual.  
  
 O valor original da propriedade atual é definido pelo [CMFCPropertyGridProperty::CMFCPropertyGridProperty](#cmfcpropertygridproperty) construtor, modificado pelo [CMFCPropertyGridProperty::SetOriginalValue](#setoriginalvalue) método e reinicie o [CMFCPropertyGridProperty::ResetOriginalValue](#resetoriginalvalue) método.  
  
##  <a name="a-namegetparenta--cmfcpropertygridpropertygetparent"></a><a name="getparent"></a>CMFCPropertyGridProperty::GetParent  
 Recupera um ponteiro para uma propriedade pai.  
  
```  
CMFCPropertyGridProperty* GetParent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de propriedade do pai, ou `NULL` para a propriedade de nível superior.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecta--cmfcpropertygridpropertygetrect"></a><a name="getrect"></a>CMFCPropertyGridProperty::GetRect  
 Recupera o retângulo delimitador de uma propriedade.  
  
```  
CRect GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que descreve o retângulo delimitador.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetsubitema--cmfcpropertygridpropertygetsubitem"></a><a name="getsubitem"></a>CMFCPropertyGridProperty::GetSubItem  
 Recupera uma propriedade subpropriedades identificada por um índice baseado em zero.  
  
```  
CMFCPropertyGridProperty* GetSubItem(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice baseado em zero da propriedade a recuperar. Esse parâmetro é inválido, se ele for menor que zero ou maior que ou igual ao número de subpropriedades.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de propriedade que é um item filho desta propriedade.  
  
 -ou-  
  
 No modo de varejo, `NULL` se o `nIndex` parâmetro é inválido. No modo de depuração, esse método declara.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetsubitemscounta--cmfcpropertygridpropertygetsubitemscount"></a><a name="getsubitemscount"></a>CMFCPropertyGridProperty::GetSubItemsCount  
 Recupera o número de itens de subpastas.  
  
```  
int GetSubItemsCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens filho.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetvaluea--cmfcpropertygridpropertygetvalue"></a><a name="getvalue"></a>CMFCPropertyGridProperty::GetValue  
 Recupera um valor de propriedade.  
  
```  
virtual const _variant_t& GetValue() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma variante que contém o valor da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetvaluetooltipa--cmfcpropertygridpropertygetvaluetooltip"></a><a name="getvaluetooltip"></a>CMFCPropertyGridProperty::GetValueTooltip  
 Chamado pela estrutura para recuperar a representação de texto do valor da propriedade que é exibido em uma dica de ferramenta.  
  
```  
virtual CString GetValueTooltip();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém a representação textual do valor da propriedade. Por padrão, esse valor é a cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehasbuttona--cmfcpropertygridpropertyhasbutton"></a><a name="hasbutton"></a>CMFCPropertyGridProperty::HasButton  
 Indica se uma propriedade contém um botão.  
  
```  
virtual BOOL HasButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se uma propriedade contiver um botão (ou lista de propriedades); Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehittesta--cmfcpropertygridpropertyhittest"></a><a name="hittest"></a>CMFCPropertyGridProperty::HitTest  
 Aponta para o objeto de propriedade que corresponde ao item de lista de propriedade que corresponde a um ponto.  
  
```  
CMFCPropertyGridProperty* HitTest(
    CPoint point,  
    CMFCPropertyGridProperty::ClickArea* pnArea=NULL);

 
CMFCPropertyGridProperty* HitTest(
    CPoint pt,  
    CMFCPropertyGridProperty::ClickArea* pnArea=NULL,  
    BOOL bPropsOnly=FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto de teste, em coordenadas do cliente. Normalmente, este parâmetro é o local atual do ponteiro do mouse.  
  
 [in] `pt`  
 O ponto de teste, em coordenadas do cliente.  
  
 [out] `pnArea`  
 Quando este método retorna, indica a área que contém o ponto especificado. Para obter mais informações, consulte Comentários. O valor padrão é `NULL`.  
  
 [in] `bPropsOnly`  
 `TRUE`Para testar qualquer área no controle de propriedade; `FALSE` para testar somente a área de descrição. O valor padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de propriedade ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método testa a propriedade subelementos se o ponto especificado não foi encontrado em qualquer um dos itens de propriedade.  
  
 A tabela a seguir lista os valores que podem ser retornados para o `pnArea` parâmetro.  
  
|Área|Descrição|  
|----------|-----------------|  
|`ClickArea::ClickExpandBox`|O controle de caixa de expansão, que é designado por um sinal de adição (+).|  
|`ClickArea::ClickName`|O nome da propriedade.|  
|`ClickArea::ClickValue`|O valor da propriedade.|  
  
##  <a name="a-nameinita--cmfcpropertygridpropertyinit"></a><a name="init"></a>CMFCPropertyGridProperty::Init  
 Chamado pela estrutura para inicializar um objeto de propriedade.  
  
```  
void Init();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisallowedita--cmfcpropertygridpropertyisallowedit"></a><a name="isallowedit"></a>CMFCPropertyGridProperty::IsAllowEdit  
 Indica se uma propriedade é editável.  
  
```  
BOOL IsAllowEdit() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade é editável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisenableda--cmfcpropertygridpropertyisenabled"></a><a name="isenabled"></a>CMFCPropertyGridProperty::IsEnabled  
 Indica se uma propriedade está habilitada ou desabilitada.  
  
```  
BOOL IsEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade estiver habilitada; `FALSE` se a propriedade está desabilitada.  
  
### <a name="remarks"></a>Comentários  
 Informa se uma propriedade está habilitada ou desabilitada.  
  
##  <a name="a-nameisexpandeda--cmfcpropertygridpropertyisexpanded"></a><a name="isexpanded"></a>CMFCPropertyGridProperty::IsExpanded  
 Indica se uma propriedade é expandida ou recolhida.  
  
```  
BOOL IsExpanded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade é expandida; `FALSE` se a propriedade é recolhida.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisgroupa--cmfcpropertygridpropertyisgroup"></a><a name="isgroup"></a>CMFCPropertyGridProperty::IsGroup  
 Indica se a propriedade atual representa um grupo.  
  
```  
BOOL IsGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o objeto atual da propriedade representa um grupo; `FALSE` se a propriedade representa um valor.  
  
### <a name="remarks"></a>Comentários  
 A *grupo* é uma coleção de propriedades relacionadas em um controle de grade de propriedade. Se o controle é exibido hierarquicamente, o *nome do grupo* é exibido como um título de categoria na linha acima do grupo.  
  
##  <a name="a-nameisinplaceeditinga--cmfcpropertygridpropertyisinplaceediting"></a><a name="isinplaceediting"></a>CMFCPropertyGridProperty::IsInPlaceEditing  
 Indica se a propriedade atual é editável.  
  
```  
BOOL IsInPlaceEditing() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade atual é editável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameismodifieda--cmfcpropertygridpropertyismodified"></a><a name="ismodified"></a>CMFCPropertyGridProperty::IsModified  
 Indica se a propriedade atual é modificada.  
  
```  
BOOL IsModified() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade é modificada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisparentexpandeda--cmfcpropertygridpropertyisparentexpanded"></a><a name="isparentexpanded"></a>CMFCPropertyGridProperty::IsParentExpanded  
 Indica se os pais da propriedade atual são expandidos.  
  
```  
BOOL IsParentExpanded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se todos os pais da propriedade atual são expandidos; `FALSE` se as propriedades pai são recolhidas.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisselecteda--cmfcpropertygridpropertyisselected"></a><a name="isselected"></a>CMFCPropertyGridProperty::IsSelected  
 Indica se a propriedade atual está selecionada.  
  
```  
virtual BOOL IsSelected() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade atual está selecionada. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameissubitema--cmfcpropertygridpropertyissubitem"></a><a name="issubitem"></a>CMFCPropertyGridProperty::IsSubItem  
 Indica se a propriedade especificada é um item de subpropriedades da propriedade atual.  
  
```  
BOOL IsSubItem(CMFCPropertyGridProperty* pProp) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pProp`  
 Um ponteiro para uma propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade especificada é um item de subpropriedades da propriedade atual; Caso contrário, `FALSE`.  
  
##  <a name="a-nameisvaluechangeda--cmfcpropertygridpropertyisvaluechanged"></a><a name="isvaluechanged"></a>CMFCPropertyGridProperty::IsValueChanged  
 Indica se o valor da propriedade atual foi alterado.  
  
```  
virtual BOOL IsValueChanged() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o valor da propriedade atual foi alterado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisvisiblea--cmfcpropertygridpropertyisvisible"></a><a name="isvisible"></a>CMFCPropertyGridProperty::IsVisible  
 Indica se a propriedade atual está visível.  
  
```  
BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade atual estiver visível; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemstrformatdoublea--cmfcpropertygridpropertymstrformatdouble"></a><a name="m_strformatdouble"></a>CMFCPropertyGridProperty::m_strFormatDouble  
 Contém uma cadeia de caracteres de formato para um valor do tipo double.  
  
```  
static CString m_strFormatDouble;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemstrformatfloata--cmfcpropertygridpropertymstrformatfloat"></a><a name="m_strformatfloat"></a>CMFCPropertyGridProperty::m_strFormatFloat  
 Contém uma cadeia de caracteres de formato para um valor de tipo flutuante.  
  
```  
static CString m_strFormatFloat;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemstrformatlonga--cmfcpropertygridpropertymstrformatlong"></a><a name="m_strformatlong"></a>CMFCPropertyGridProperty::m_strFormatLong  
 Contém uma cadeia de caracteres de formato para um valor de tipo long.  
  
```  
static CString m_strFormatLong;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemstrformatshorta--cmfcpropertygridpropertymstrformatshort"></a><a name="m_strformatshort"></a>CMFCPropertyGridProperty::m_strFormatShort  
 Contém uma cadeia de caracteres de formato para um valor do tipo curto.  
  
```  
static CString m_strFormatShort;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonclickbuttona--cmfcpropertygridpropertyonclickbutton"></a><a name="onclickbutton"></a>CMFCPropertyGridProperty::OnClickButton  
 Chamado pela estrutura quando o usuário clica em um botão que está contido em uma propriedade.  
  
```  
virtual void OnClickButton(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Um ponto nas coordenadas do cliente.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonclicknamea--cmfcpropertygridpropertyonclickname"></a><a name="onclickname"></a>CMFCPropertyGridProperty::OnClickName  
 Chamado por um controle de lista de propriedade pai quando um usuário clica no campo nome de uma propriedade.  
  
```  
virtual void OnClickName(CPoint C);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `C`|Um ponto nas coordenadas do cliente.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonclickvaluea--cmfcpropertygridpropertyonclickvalue"></a><a name="onclickvalue"></a>CMFCPropertyGridProperty::OnClickValue  
 Chamado por um controle de lista de propriedade pai quando um usuário clica no campo valor de uma propriedade.  
  
```  
virtual BOOL OnClickValue(
    UINT uiMsg,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiMsg`  
 Uma mensagem de mouse.  
  
 [in] `point`  
 Um ponto nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a mensagem do mouse especificada é processada por esse método; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método retorna `FALSE` se a propriedade atual não é editável. Caso contrário, a edição ou controle de rotação que está associado essa propriedade processa a mensagem de mouse especificado, e, em seguida, esse método retornará `TRUE`.  
  
##  <a name="a-nameonclosecomboa--cmfcpropertygridpropertyonclosecombo"></a><a name="onclosecombo"></a>CMFCPropertyGridProperty::OnCloseCombo  
 Chamado pela estrutura quando uma caixa de combinação que está contida em uma propriedade é fechada.  
  
```  
virtual void OnCloseCombo();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonctlcolora--cmfcpropertygridpropertyonctlcolor"></a><a name="onctlcolor"></a>CMFCPropertyGridProperty::OnCtlColor  
 Chamado pela estrutura quando ele deve recuperar um pincel para preencher a cor de plano de fundo de uma propriedade.  
  
```  
virtual HBRUSH OnCtlColor(
    CDC* pDC,  
    UINT nCtlColor);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 [in] `nCtlColor`  
 (Esse parâmetro não for usado).  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para um pincel se esse método for bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondblclka--cmfcpropertygridpropertyondblclk"></a><a name="ondblclk"></a>CMFCPropertyGridProperty::OnDblClk  
 Chamado pela estrutura quando o usuário clicar duas vezes uma propriedade.  
  
```  
virtual BOOL OnDblClk(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Um ponto nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método seleciona o próximo item de propriedade no controle de lista de propriedade.  
  
##  <a name="a-nameondestroywindowa--cmfcpropertygridpropertyondestroywindow"></a><a name="ondestroywindow"></a>CMFCPropertyGridProperty::OnDestroyWindow  
 Chamado pela estrutura quando uma propriedade é destruída ou quando a edição é concluída.  
  
```  
virtual void OnDestroyWindow();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawbuttona--cmfcpropertygridpropertyondrawbutton"></a><a name="ondrawbutton"></a>CMFCPropertyGridProperty::OnDrawButton  
 Chamado pela estrutura para desenhar um botão que está contido em uma propriedade.  
  
```  
virtual void OnDrawButton(
    CDC* pDC,  
    CRect rectButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectButton`  
 Um retângulo que especifica onde desenhar um botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawdescriptiona--cmfcpropertygridpropertyondrawdescription"></a><a name="ondrawdescription"></a>CMFCPropertyGridProperty::OnDrawDescription  
 Chamado pela estrutura para desenhar a descrição da propriedade.  
  
```  
virtual void OnDrawDescription(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Um retângulo que especifica onde desenhar a descrição da propriedade.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método desenha o nome da propriedade e a descrição da fonte usado pelo controle de lista da propriedade do pai. A descrição da propriedade é desenhada no estilo normal e o nome da propriedade é desenhado no estilo em negrito.  
  
##  <a name="a-nameondrawexpandboxa--cmfcpropertygridpropertyondrawexpandbox"></a><a name="ondrawexpandbox"></a>CMFCPropertyGridProperty::OnDrawExpandBox  
 Chamado pela estrutura para desenhar um controle de caixa de expansão perto de uma propriedade que contém subpropriedades.  
  
```  
virtual void OnDrawExpandBox(
    CDC* pDC,  
    CRect rectExpand);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectExpand`  
 Um retângulo que especifica onde desenhar o controle de caixa de expansão.  
  
### <a name="remarks"></a>Comentários  
 Clique no controle de caixa de expansão para expandir ou recolher uma lista de subpropriedades. O controle de caixa de expansão é designado por um quadrado que contém um sinal de adição (+) ou subtração (-). Um sinal de mais indica que a propriedade pode ser expandida para mostrar uma lista de subpropriedades. Um sinal de subtração indica que a lista pode ser recolhida para mostrar apenas a propriedade.  
  
##  <a name="a-nameondrawnamea--cmfcpropertygridpropertyondrawname"></a><a name="ondrawname"></a>CMFCPropertyGridProperty::OnDrawName  
 Chamado pela estrutura para exibir o nome da propriedade.  
  
```  
virtual void OnDrawName(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Um retângulo que especifica onde desenhar o nome da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawvaluea--cmfcpropertygridpropertyondrawvalue"></a><a name="ondrawvalue"></a>CMFCPropertyGridProperty::OnDrawValue  
 Chamado pela estrutura para exibir o valor da propriedade.  
  
```  
virtual void OnDrawValue(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Um retângulo que especifica onde desenhar o valor da propriedade.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonedita--cmfcpropertygridpropertyonedit"></a><a name="onedit"></a>CMFCPropertyGridProperty::OnEdit  
 Chamado pela estrutura quando o usuário está prestes a modificar um valor da propriedade.  
  
```  
virtual BOOL OnEdit(LPPOINT lptClick);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lptClick`  
 (Esse parâmetro não for usado). Um ponteiro para um ponto, nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a operação de edição é iniciado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pela estrutura quando o usuário está prestes a modificar um valor da propriedade. Por padrão, esse método inicia o editor apropriado para um controle de caixa de combinação ou um controle de rotação.  
  
##  <a name="a-nameonendedita--cmfcpropertygridpropertyonendedit"></a><a name="onendedit"></a>CMFCPropertyGridProperty::OnEndEdit  
 Chamado pela estrutura quando o usuário modificando um valor de propriedade.  
  
```  
virtual BOOL OnEndEdit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método destrói o controle de edição atual e, em seguida, retorna `TRUE`.  
  
##  <a name="a-nameonkillfocusa--cmfcpropertygridpropertyonkillfocus"></a><a name="onkillfocus"></a>CMFCPropertyGridProperty::OnKillFocus  
 Chamado pela estrutura quando a propriedade perde o foco de entrada.  
  
```  
virtual BOOL OnKillFocus(CWnd*);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `CWnd`|(Não usado). Ponteiro para uma janela.|  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método faz nada e, em seguida, retorna `TRUE`. Se você substituir esse método, retornar `TRUE` se a estrutura pode encerrar a operação de edição quando a propriedade perde o foco de entrada.  
  
##  <a name="a-nameonkillselectiona--cmfcpropertygridpropertyonkillselection"></a><a name="onkillselection"></a>CMFCPropertyGridProperty::OnKillSelection  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnKillSelection(CMFCPropertyGridProperty*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CMFCPropertyGridProperty*`  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonpossizechangeda--cmfcpropertygridpropertyonpossizechanged"></a><a name="onpossizechanged"></a>CMFCPropertyGridProperty::OnPosSizeChanged  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnPosSizeChanged(CRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CRect`  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonrclicknamea--cmfcpropertygridpropertyonrclickname"></a><a name="onrclickname"></a>CMFCPropertyGridProperty::OnRClickName  
 Chamado pela estrutura quando o usuário clica no botão direito do mouse na área de nome de propriedade.  
  
```  
virtual void OnRClickName(CPoint C);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `C`|Um ponto nas coordenadas do cliente.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonrclickvaluea--cmfcpropertygridpropertyonrclickvalue"></a><a name="onrclickvalue"></a>CMFCPropertyGridProperty::OnRClickValue  
 Chamado pela estrutura quando o usuário clica no botão direito do mouse na área de valor de propriedade.  
  
```  
virtual void OnRClickValue(
    CPoint C,  
    BOOL B);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `C`|Um ponto nas coordenadas do cliente.|  
|[in] `B`|Um booliano.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não faz nada e o `B` parâmetro não tiver nenhuma finalidade predefinida.  
  
##  <a name="a-nameonselectcomboa--cmfcpropertygridpropertyonselectcombo"></a><a name="onselectcombo"></a>CMFCPropertyGridProperty::OnSelectCombo  
 Chamado pela estrutura quando o usuário seleciona um item da caixa de combinação editável.  
  
```  
virtual void OnSelectCombo();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método usa o texto do item selecionado para atualizar o valor da propriedade.  
  
##  <a name="a-nameonsetcursora--cmfcpropertygridpropertyonsetcursor"></a><a name="onsetcursor"></a>CMFCPropertyGridProperty::OnSetCursor  
 Chamado pela estrutura quando o ponteiro do mouse se move para um item de propriedade.  
  
```  
virtual BOOL OnSetCursor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a propriedade atual é um tipo variante ou uma lista de valores, e esse método carrega com êxito o cursor do mouse de (i) do ponto de inserção; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 This method supports the following variant types: `VT_INT`, `VT_I2`, `VT_I4`, `VT_UINT`, `VT_UI1`, `VT_UI2`, `VT_UI4`, `VT_R4`, `VT_R8`, and `VT_BSTR`.  
  
##  <a name="a-nameonsetselectiona--cmfcpropertygridpropertyonsetselection"></a><a name="onsetselection"></a>CMFCPropertyGridProperty::OnSetSelection  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnSetSelection(CMFCPropertyGridProperty*);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CMFCPropertyGridProperty*`  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="a-nameonupdatevaluea--cmfcpropertygridpropertyonupdatevalue"></a><a name="onupdatevalue"></a>CMFCPropertyGridProperty::OnUpdateValue  
 Chamado pela estrutura quando o valor de uma propriedade editável é alterado.  
  
```  
virtual BOOL OnUpdateValue();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namepushchara--cmfcpropertygridpropertypushchar"></a><a name="pushchar"></a>CMFCPropertyGridProperty::PushChar  
 Chamado a partir do controle de lista de propriedade quando a propriedade for selecionada e o usuário insere um caractere de nova.  
  
```  
virtual BOOL PushChar(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nChar`  
 Um caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se continuar a operação de edição; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método dá suporte a uma propriedade que é uma lista de valores ou um dos seguintes tipos variantes: `VT_INT`, `VT_I2`, `VT_I4`, `VT_UINT`, `VT_UI1`, `VT_UI2`, `VT_UI4`, `VT_R4`, `VT_R8`, e `VT_BSTR`.  
  
##  <a name="a-nameredrawa--cmfcpropertygridpropertyredraw"></a><a name="redraw"></a>CMFCPropertyGridProperty::Redraw  
 Redesenha a propriedade.  
  
```  
void Redraw();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovealloptionsa--cmfcpropertygridpropertyremovealloptions"></a><a name="removealloptions"></a>CMFCPropertyGridProperty::RemoveAllOptions  
 Remove todas as opções (itens) de uma propriedade.  
  
```  
void RemoveAllOptions();
```  
  
### <a name="remarks"></a>Comentários  
 Opções também são conhecidos como itens de lista de um controle de lista de propriedade.  
  
##  <a name="a-nameremovesubitema--cmfcpropertygridpropertyremovesubitem"></a><a name="removesubitem"></a>CMFCPropertyGridProperty::RemoveSubItem  
 Remove o item especificado de subpropriedades.  
  
```  
BOOL RemoveSubItem(
    CMFCPropertyGridProperty*& pProp,  
    BOOL bDelete=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pProp`  
 Ponteiro para um item de subpropriedades da propriedade.  
  
 [in] `bDelete`  
 `TRUE`Para excluir o objeto de propriedade especificado pelo `pProp` parâmetro; caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Especifique `FALSE` para o `bDelete` parâmetro se você pretende mover o item especificado de subpropriedades; ou seja, remova o subitem e adicioná-lo em outro lugar.  
  
##  <a name="a-nameresetoriginalvaluea--cmfcpropertygridpropertyresetoriginalvalue"></a><a name="resetoriginalvalue"></a>CMFCPropertyGridProperty::ResetOriginalValue  
 Restaura o valor original de uma propriedade editada.  
  
```  
virtual void ResetOriginalValue();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetdataa--cmfcpropertygridpropertysetdata"></a><a name="setdata"></a>CMFCPropertyGridProperty::SetData  
 Associa um `DWORD` valor com uma propriedade.  
  
```  
void SetData(DWORD_PTR dwData);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Um valor de 32 bits específicos do aplicativo, como um inteiro ou um ponteiro para outros dados.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCPropertyGridProperty::GetData](#getdata) método para recuperar o `DWORD` valor. Use o [CMFCPropertyGridCtrl::FindItemByData](../../mfc/reference/cmfcpropertygridctrl-class.md#finditembydata) método para localizar o item de lista de propriedade associado especificado `DWORD` valor.  
  
##  <a name="a-namesetdescriptiona--cmfcpropertygridpropertysetdescription"></a><a name="setdescription"></a>CMFCPropertyGridProperty::SetDescription  
 Especifica o texto que descreve a propriedade atual.  
  
```  
void SetDescription(const CString& strDescr);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strDescr`  
 Texto que descreve a propriedade atual.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetnamea--cmfcpropertygridpropertysetname"></a><a name="setname"></a>CMFCPropertyGridProperty::SetName  
 Define o nome de uma propriedade.  
  
```  
void SetName(
    LPCTSTR lpszName,  
    BOOL bRedraw=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome da propriedade.  
  
 [in] `bRedraw`  
 `TRUE`para redesenhar a propriedade imediatamente. Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetoriginalvaluea--cmfcpropertygridpropertysetoriginalvalue"></a><a name="setoriginalvalue"></a>CMFCPropertyGridProperty::SetOriginalValue  
 Define o valor original de uma propriedade editável.  
  
```  
virtual void SetOriginalValue(const COleVariant& varValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `varValue`  
 Um valor.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCPropertyGridProperty::ResetOriginalValue](#resetoriginalvalue) método para redefinir o valor original de uma propriedade editada.  
  
##  <a name="a-namesetvaluea--cmfcpropertygridpropertysetvalue"></a><a name="setvalue"></a>CMFCPropertyGridProperty::SetValue  
 Define o valor de uma propriedade de grade de propriedade.  
  
```  
virtual void SetValue(const _variant_t& varValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `varValue`  
 Uma referência a um valor.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameshowa--cmfcpropertygridpropertyshow"></a><a name="show"></a>CMFCPropertyGridProperty::Show  
 Mostra ou oculta uma propriedade.  
  
```  
void Show(
    BOOL bShow=TRUE,  
    BOOL bAdjustLayout=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 `TRUE`Para exibir a propriedade atual e seus subelementos; `FALSE` para ocultar a propriedade atual e seus subelementos. O valor padrão é `TRUE`.  
  
 [in] `bAdjustLayout`  
 `TRUE`para recalcular a desenhar o rótulo e o valor de uma propriedade e, em seguida, desenhe a propriedade; `FALSE` usar cálculos existentes para desenhar a propriedade. O valor padrão é `TRUE`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)

