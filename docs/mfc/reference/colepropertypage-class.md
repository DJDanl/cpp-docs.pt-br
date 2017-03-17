---
title: Classe COlePropertyPage | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COlePropertyPage
- AFXCTL/COlePropertyPage
- AFXCTL/COlePropertyPage::COlePropertyPage
- AFXCTL/COlePropertyPage::GetControlStatus
- AFXCTL/COlePropertyPage::GetObjectArray
- AFXCTL/COlePropertyPage::GetPageSite
- AFXCTL/COlePropertyPage::IgnoreApply
- AFXCTL/COlePropertyPage::IsModified
- AFXCTL/COlePropertyPage::OnEditProperty
- AFXCTL/COlePropertyPage::OnHelp
- AFXCTL/COlePropertyPage::OnInitDialog
- AFXCTL/COlePropertyPage::OnObjectsChanged
- AFXCTL/COlePropertyPage::OnSetPageSite
- AFXCTL/COlePropertyPage::SetControlStatus
- AFXCTL/COlePropertyPage::SetDialogResource
- AFXCTL/COlePropertyPage::SetHelpInfo
- AFXCTL/COlePropertyPage::SetModifiedFlag
- AFXCTL/COlePropertyPage::SetPageName
dev_langs:
- C++
helpviewer_keywords:
- OLE property pages
- custom controls [MFC], properties
- COlePropertyPage class
- properties [C++], displaying
- displaying properties
- property pages, OLE
ms.assetid: e9972872-8e6b-4550-905e-d36a274d64dc
caps.latest.revision: 23
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 20d70cc25305fc5d17860314d9cfbe927df65c70
ms.lasthandoff: 02/25/2017

---
# <a name="colepropertypage-class"></a>Classe COlePropertyPage
Usado para exibir as propriedades de um controle personalizado em uma interface gráfica, semelhante a uma caixa de diálogo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE COlePropertyPage : public CDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertyPage::COlePropertyPage](#colepropertypage)|Constrói um objeto `COlePropertyPage`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COlePropertyPage::GetControlStatus](#getcontrolstatus)|Indica se o usuário tiver modificado o valor no controle.|  
|[COlePropertyPage::GetObjectArray](#getobjectarray)|Retorna a matriz de objetos sendo editado pela página de propriedades.|  
|[COlePropertyPage::GetPageSite](#getpagesite)|Retorna um ponteiro para a página de propriedades `IPropertyPageSite` interface.|  
|[COlePropertyPage::IgnoreApply](#ignoreapply)|Determina quais controles não habilitar o botão Aplicar.|  
|[COlePropertyPage::IsModified](#ismodified)|Indica se o usuário modificou a página de propriedades.|  
|[COlePropertyPage::OnEditProperty](#oneditproperty)|Chamado pela estrutura quando o usuário edita uma propriedade.|  
|[COlePropertyPage::OnHelp](#onhelp)|Chamado pela estrutura quando o usuário chama a Ajuda.|  
|[COlePropertyPage::OnInitDialog](#oninitdialog)|Chamado pela estrutura quando a página de propriedade é inicializada.|  
|[COlePropertyPage::OnObjectsChanged](#onobjectschanged)|Chamado pela estrutura quando outro controle OLE, com novas propriedades, é escolhido.|  
|[COlePropertyPage::OnSetPageSite](#onsetpagesite)|Chamado pela estrutura quando o quadro de propriedades fornece o local da página.|  
|[COlePropertyPage::SetControlStatus](#setcontrolstatus)|Define um sinalizador que indica se o usuário tiver modificado o valor no controle.|  
|[COlePropertyPage::SetDialogResource](#setdialogresource)|Define caixa de diálogo do recurso a página de propriedades.|  
|[COlePropertyPage::SetHelpInfo](#sethelpinfo)|Define o texto da ajuda breve da página de propriedade, o nome do seu arquivo de Ajuda e seu contexto de Ajuda.|  
|[COlePropertyPage::SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica se o usuário modificou a página de propriedades.|  
|[COlePropertyPage::SetPageName](#setpagename)|Define o nome da página de propriedade (legenda).|  
  
## <a name="remarks"></a>Comentários  
 Por exemplo, uma página de propriedades pode incluir um controle de edição que permite que o usuário exiba e modifique a propriedade da legenda do controle.  
  
 Cada propriedade de controle personalizado ou estoque pode ter um controle de caixa de diálogo que permite que usuário do controle exibir o valor da propriedade atual e modificar esse valor se necessário.  
  
 Para obter mais informações sobre como usar o `COlePropertyPage`, consulte o artigo [controles ActiveX: páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 `COlePropertyPage`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h  
  
##  <a name="colepropertypage"></a>COlePropertyPage::COlePropertyPage  
 Constrói um objeto `COlePropertyPage`.  
  
```  
COlePropertyPage(
    UINT idDlg,  
    UINT idCaption);
```  
  
### <a name="parameters"></a>Parâmetros  
 *idDlg*  
 ID de recurso do modelo de caixa de diálogo.  
  
 *idCaption*  
 ID de recurso de legenda da página de propriedades.  
  
### <a name="remarks"></a>Comentários  
 Quando você implementa uma subclasse de `COlePropertyPage`, deve usar o construtor da subclasse o `COlePropertyPage` construtor para identificar o recurso de modelo de caixa de diálogo na qual baseia-se a página de propriedades e o recurso de cadeia de caracteres que contém a legenda.  
  
##  <a name="getcontrolstatus"></a>COlePropertyPage::GetControlStatus  
 Determina se o usuário tiver modificado o valor do controle de página de propriedade com a ID de recurso especificado.  
  
```  
BOOL GetControlStatus(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID de recurso de um controle de página de propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o valor do controle tiver sido modificada; caso contrário **FALSE**.  
  
##  <a name="getobjectarray"></a>COlePropertyPage::GetObjectArray  
 Retorna a matriz de objetos sendo editado pela página de propriedades.  
  
```  
LPDISPATCH* GetObjectArray(ULONG* pnObjects);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pnObjects`  
 Ponteiro para um inteiro longo não assinado que receberá o número de objetos que está sendo editado pela página.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma matriz de `IDispatch` ponteiros, que são usados para acessar as propriedades de cada controle na página de propriedades. O chamador não deve liberar esses ponteiros de interface.  
  
### <a name="remarks"></a>Comentários  
 Cada objeto de página de propriedade mantém uma matriz de ponteiros para o `IDispatch` interfaces dos objetos sendo editados pela página. Essa função define seu `pnObjects` argumento para o número de elementos na matriz e retorna um ponteiro para o primeiro elemento da matriz.  
  
##  <a name="getpagesite"></a>COlePropertyPage::GetPageSite  
 Obtém um ponteiro para a página de propriedades `IPropertyPageSite` interface.  
  
```  
LPPROPERTYPAGESITE GetPageSite();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a página de propriedades `IPropertyPageSite` interface.  
  
### <a name="remarks"></a>Comentários  
 Controles e contêineres cooperam para que os usuários podem procurar e editar propriedades de controle. O controle fornece páginas de propriedades, cada um deles é um objeto OLE que permite ao usuário editar um conjunto de propriedades relacionadas. O contêiner fornece um quadro de propriedade que exibe as páginas de propriedades. Para cada página, o quadro de propriedades fornece um site de página, que oferece suporte a `IPropertyPageSite` interface.  
  
##  <a name="ignoreapply"></a>COlePropertyPage::IgnoreApply  
 Determina quais controles não habilitar o botão Aplicar.  
  
```  
void IgnoreApply(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 ID do controle a ser ignorada.  
  
### <a name="remarks"></a>Comentários  
 Botão de aplicar da página de propriedade é habilitado somente quando valores de controles da página de propriedade que foi alterada. Use esta função para especificar os controles que não fazem com que o botão Aplicar ser habilitado quando alteram seus valores.  
  
##  <a name="ismodified"></a>COlePropertyPage::IsModified  
 Determina se o usuário tiver alterado quaisquer valores na página de propriedades.  
  
```  
BOOL IsModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a página de propriedades foi modificada.  
  
##  <a name="oneditproperty"></a>COlePropertyPage::OnEditProperty  
 O framework chama essa função quando uma propriedade específica a ser editada.  
  
```  
virtual BOOL OnEditProperty(DISPID dispid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dispid`  
 ID de expedição da propriedade que está sendo editada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão **FALSE**. Substituições dessa função devem retornar **TRUE**.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituí-la para definir o foco para o controle apropriado na página. A implementação padrão não faz nada e retorna **FALSE**.  
  
##  <a name="onhelp"></a>COlePropertyPage::OnHelp  
 O framework chama essa função quando o usuário solicita ajuda on-line.  
  
```  
virtual BOOL OnHelp(LPCTSTR lpszHelpDir);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszHelpDir*  
 Diretório que contém o arquivo de Ajuda da página de propriedades.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Substituí-la se sua página de propriedade necessário realizar nenhuma ação especial quando o usuário acessa a Ajuda. A implementação padrão não faz nada e retorna **FALSE**, que instrui a estrutura chamar WinHelp.  
  
##  <a name="oninitdialog"></a>COlePropertyPage::OnInitDialog  
 O framework chama essa função quando a caixa de diálogo da página de propriedade é inicializada.  
  
```  
virtual BOOL OnInitDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Substituí-la se nenhuma ação especial é necessária quando a caixa de diálogo é inicializada. As chamadas de implementação padrão `CDialog::OnInitDialog` e retorna **FALSE**.  
  
##  <a name="onobjectschanged"></a>COlePropertyPage::OnObjectsChanged  
 Chamado pela estrutura quando outro controle OLE, com novas propriedades, é escolhido.  
  
```  
virtual void OnObjectsChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Ao exibir as propriedades de um controle OLE no ambiente de desenvolvedor, uma caixa de diálogo sem janela restrita é usada para exibir as páginas de propriedade. Se outro controle for selecionado, um conjunto diferente de páginas de propriedades deve exibido para o novo conjunto de propriedades. O framework chama essa função para notificar a página de propriedade da alteração.  
  
 Substitua essa função para receber notificação desta ação e realizar ações especiais.  
  
##  <a name="onsetpagesite"></a>COlePropertyPage::OnSetPageSite  
 O framework chama essa função quando o quadro de propriedades fornece o site da página da página de propriedade.  
  
```  
virtual void OnSetPageSite();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão carrega a legenda da página e tenta determinar o tamanho da página do recurso de caixa de diálogo. Substituir essa função se sua página de propriedades exigir nenhuma providência; sua substituição deve chamar a implementação da classe base.  
  
##  <a name="setcontrolstatus"></a>COlePropertyPage::SetControlStatus  
 Altera o status de um controle de página de propriedade.  
  
```  
BOOL SetControlStatus(
    UINT nID,  
    BOOL bDirty);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Contém a ID de um controle de página de propriedade.  
  
 `bDirty`  
 Especifica se um campo da página de propriedades foi modificado. Definido como **TRUE** se o campo tiver sido modificado, **FALSE** se não tiver sido modificado.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE**, se o controle especificado foi definida; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Se o status de um controle de página de propriedade está sujo quando a página de propriedades é fechada ou o botão Aplicar é escolhido, a propriedade do controle será atualizada com o valor apropriado.  
  
##  <a name="setdialogresource"></a>COlePropertyPage::SetDialogResource  
 Define caixa de diálogo do recurso a página de propriedades.  
  
```  
void SetDialogResource(HGLOBAL hDialog);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hDialog*  
 Identificador para recurso de caixa de diálogo da página de propriedades.  
  
##  <a name="sethelpinfo"></a>COlePropertyPage::SetHelpInfo  
 Especifica o contexto de sua página de propriedades, o nome do arquivo de Ajuda e informações de dica de ferramenta.  
  
```  
void SetHelpInfo(
    LPCTSTR lpszDocString,  
    LPCTSTR lpszHelpFile = NULL,  
    DWORD dwHelpContext = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszDocString*  
 Uma cadeia de caracteres que contém informações de ajuda breves para exibição em uma barra de status ou de outro local.  
  
 `lpszHelpFile`  
 Nome do arquivo de Ajuda da página de propriedades.  
  
 *dwHelpContext*  
 Contexto da Ajuda da página de propriedades.  
  
##  <a name="setmodifiedflag"></a>COlePropertyPage::SetModifiedFlag  
 Indica se o usuário modificou a página de propriedades.  
  
```  
void SetModifiedFlag(BOOL bModified = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bModified`  
 Especifica o novo valor de sinalizador modificado da página de propriedades.  
  
##  <a name="setpagename"></a>COlePropertyPage::SetPageName  
 Define o nome da página de propriedade, o que o quadro de propriedades normalmente será exibido na guia da página.  
  
```  
void SetPageName(LPCTSTR lpszPageName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszPageName*  
 Ponteiro para uma cadeia de caracteres que contém o nome da página de propriedade.  
  
## <a name="see-also"></a>Consulte também  
 [CIRC3 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC TESTHELP](../../visual-cpp-samples.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)

