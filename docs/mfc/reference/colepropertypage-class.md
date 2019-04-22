---
title: Classe COlePropertyPage
ms.date: 11/04/2016
f1_keywords:
- COlePropertyPage
- AFXCTL/COlePropertyPage
- AFXCTL/COlePropertyPage::COlePropertyPage
- AFXCTL/COlePropertyPage::GetControlStatus
- AFXCTL/COlePropertyPage::GetObjectArray
- AFXCTL/COlePropertyPage::GetPageSite
- AFXCTL/COlePropertyPage::OVERWRITEApply
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
helpviewer_keywords:
- COlePropertyPage [MFC], COlePropertyPage
- COlePropertyPage [MFC], GetControlStatus
- COlePropertyPage [MFC], GetObjectArray
- COlePropertyPage [MFC], GetPageSite
- COlePropertyPage [MFC], IgnoreApply
- COlePropertyPage [MFC], IsModified
- COlePropertyPage [MFC], OnEditProperty
- COlePropertyPage [MFC], OnHelp
- COlePropertyPage [MFC], OnInitDialog
- COlePropertyPage [MFC], OnObjectsChanged
- COlePropertyPage [MFC], OnSetPageSite
- COlePropertyPage [MFC], SetControlStatus
- COlePropertyPage [MFC], SetDialogResource
- COlePropertyPage [MFC], SetHelpInfo
- COlePropertyPage [MFC], SetModifiedFlag
- COlePropertyPage [MFC], SetPageName
ms.assetid: e9972872-8e6b-4550-905e-d36a274d64dc
ms.openlocfilehash: 8253b2c2fa6b93ec51c7ede983ef710eed039970
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58776980"
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

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COlePropertyPage::GetControlStatus](#getcontrolstatus)|Indica se o usuário tenha modificado o valor no controle.|
|[COlePropertyPage::GetObjectArray](#getobjectarray)|Retorna a matriz de objetos que está sendo editado pela página de propriedade.|
|[COlePropertyPage::GetPageSite](#getpagesite)|Retorna um ponteiro para a página de propriedades `IPropertyPageSite` interface.|
|[COlePropertyPage::IgnoreApply](#ignoreapply)|Determina quais controles não habilitar o botão Aplicar.|
|[COlePropertyPage::IsModified](#ismodified)|Indica se o usuário modificou a página de propriedades.|
|[COlePropertyPage::OnEditProperty](#oneditproperty)|Chamado pelo framework quando o usuário edita uma propriedade.|
|[COlePropertyPage::OnHelp](#onhelp)|Chamado pelo framework quando o usuário chama a Ajuda.|
|[COlePropertyPage::OnInitDialog](#oninitdialog)|Chamado pelo framework quando a página de propriedade é inicializada.|
|[COlePropertyPage::OnObjectsChanged](#onobjectschanged)|Chamado pelo framework quando outro controle OLE, com novas propriedades, é escolhido.|
|[COlePropertyPage::OnSetPageSite](#onsetpagesite)|Chamado pelo framework quando o quadro de propriedades fornece o local da página.|
|[COlePropertyPage::SetControlStatus](#setcontrolstatus)|Define um sinalizador que indica se o usuário tenha modificado o valor no controle.|
|[COlePropertyPage::SetDialogResource](#setdialogresource)|Define o recurso de caixa de diálogo da página de propriedades.|
|[COlePropertyPage::SetHelpInfo](#sethelpinfo)|Define o texto de ajuda breve da página de propriedades, o nome do seu arquivo de Ajuda e seu contexto de Ajuda.|
|[COlePropertyPage::SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica se o usuário modificou a página de propriedades.|
|[COlePropertyPage::SetPageName](#setpagename)|Define o nome da página de propriedades (legenda).|

## <a name="remarks"></a>Comentários

Por exemplo, uma página de propriedades pode incluir um controle de edição que permite ao usuário exibir e modificar a propriedade de legenda do controle.

Cada propriedade de controle personalizado ou estoque pode ter um controle de caixa de diálogo que permite que o usuário do controle exibir o valor da propriedade atual e modificar esse valor, se necessário.

Para obter mais informações sobre como usar `COlePropertyPage`, consulte o artigo [controles ActiveX: Páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

`COlePropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="colepropertypage"></a>  COlePropertyPage::COlePropertyPage

Constrói um objeto `COlePropertyPage`.

```
COlePropertyPage(
    UINT idDlg,
    UINT idCaption);
```

### <a name="parameters"></a>Parâmetros

*idDlg*<br/>
ID de recurso do modelo de caixa de diálogo.

*idCaption*<br/>
ID do recurso da legenda da página de propriedades.

### <a name="remarks"></a>Comentários

Quando você implementa uma subclasse de `COlePropertyPage`, deve usar o construtor da sua subclasse o `COlePropertyPage` construtor para identificar o recurso de modelo de caixa de diálogo na qual baseia-se a página de propriedades e o recurso de cadeia de caracteres que contém sua legenda.

##  <a name="getcontrolstatus"></a>  COlePropertyPage::GetControlStatus

Determina se o usuário tenha modificado o valor do controle de página de propriedades com a ID de recurso especificado.

```
BOOL GetControlStatus(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID do recurso de um controle de página de propriedade.

### <a name="return-value"></a>Valor de retorno

TRUE se o valor do controle tiver sido modificado; Caso contrário, FALSE.

##  <a name="getobjectarray"></a>  COlePropertyPage::GetObjectArray

Retorna a matriz de objetos que está sendo editado pela página de propriedade.

```
LPDISPATCH* GetObjectArray(ULONG* pnObjects);
```

### <a name="parameters"></a>Parâmetros

*pnObjects*<br/>
Ponteiro para um inteiro longo sem sinal que receberá o número de objetos que está sendo editado pela página.

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma matriz de `IDispatch` ponteiros, que são usados para acessar as propriedades de cada controle na página de propriedades. O chamador não deve liberar esses ponteiros de interface.

### <a name="remarks"></a>Comentários

Cada objeto de página de propriedade mantém uma matriz de ponteiros para o `IDispatch` interfaces dos objetos que está sendo editados pela página. Essa função define seu *pnObjects* argumento para o número de elementos na matriz e retorna um ponteiro para o primeiro elemento da matriz.

##  <a name="getpagesite"></a>  COlePropertyPage::GetPageSite

Obtém um ponteiro para a página de propriedades `IPropertyPageSite` interface.

```
LPPROPERTYPAGESITE GetPageSite();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a página de propriedades `IPropertyPageSite` interface.

### <a name="remarks"></a>Comentários

Controles e contêineres cooperam para que os usuários podem procurar e editar propriedades de controle. O controle fornece páginas de propriedades, cada um deles é um objeto OLE que permite ao usuário editar um conjunto de propriedades relacionadas. O contêiner fornece um quadro de propriedade que exibe as páginas de propriedade. Para cada página, o quadro de propriedades fornece um site de página, que oferece suporte a `IPropertyPageSite` interface.

##  <a name="ignoreapply"></a>  COlePropertyPage::IgnoreApply

Determina quais controles não habilitar o botão Aplicar.

```
void IgnoreApply(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID do controle a ser ignorada.

### <a name="remarks"></a>Comentários

Botão de aplicar da página de propriedades está habilitado apenas quando os valores dos controles de página de propriedade foram alteradas. Use esta função para especificar os controles que não fazem com que o botão Aplicar ser habilitado quando seus valores se alteram.

##  <a name="ismodified"></a>  COlePropertyPage::IsModified

Determina se o usuário tiver alterado quaisquer valores na página de propriedades.

```
BOOL IsModified();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a página de propriedades foi modificada.

##  <a name="oneditproperty"></a>  COlePropertyPage::OnEditProperty

O framework chama essa função quando uma propriedade específica deve ser editado.

```
virtual BOOL OnEditProperty(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*dispid*<br/>
ID de expedição da propriedade que está sendo editada.

### <a name="return-value"></a>Valor de retorno

A implementação padrão retorna falso. Substituições dessa função devem retornar TRUE.

### <a name="remarks"></a>Comentários

Você pode substituí-la para definir o foco para o controle apropriado na página. A implementação padrão não faz nada e retornará FALSE.

##  <a name="onhelp"></a>  COlePropertyPage::OnHelp

O framework chama essa função quando o usuário solicita ajuda on-line.

```
virtual BOOL OnHelp(LPCTSTR lpszHelpDir);
```

### <a name="parameters"></a>Parâmetros

*lpszHelpDir*<br/>
Diretório que contém o arquivo de Ajuda da página de propriedades.

### <a name="return-value"></a>Valor de retorno

A implementação padrão retorna falso.

### <a name="remarks"></a>Comentários

Substituí-lo, se sua página de propriedades deve realizar nenhuma ação especial quando o usuário acessa a Ajuda. A implementação padrão não faz nada e retorna FALSE, que instrui o framework para chamar WinHelp.

##  <a name="oninitdialog"></a>  COlePropertyPage::OnInitDialog

O framework chama essa função quando a caixa de diálogo da página de propriedades é inicializada.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão retorna falso.

### <a name="remarks"></a>Comentários

Substituí-lo, se nenhuma ação especial é necessária quando a caixa de diálogo é inicializada. A implementação padrão chama `CDialog::OnInitDialog` e retornará FALSE.

##  <a name="onobjectschanged"></a>  COlePropertyPage::OnObjectsChanged

Chamado pelo framework quando outro controle OLE, com novas propriedades, é escolhido.

```
virtual void OnObjectsChanged();
```

### <a name="remarks"></a>Comentários

Ao exibir as propriedades de um controle OLE no ambiente de desenvolvedor, uma caixa de diálogo sem janela restrita é usada para exibir as páginas de propriedade. Se outro controle for selecionado, um conjunto diferente de páginas de propriedade deve ser exibido para o novo conjunto de propriedades. O framework chama essa função para notificar a página de propriedade da alteração.

Substitua essa função para receber notificação desta ação e realizar nenhuma ação especial.

##  <a name="onsetpagesite"></a>  COlePropertyPage::OnSetPageSite

O framework chama essa função quando o quadro de propriedades fornece o site da página da página de propriedades.

```
virtual void OnSetPageSite();
```

### <a name="remarks"></a>Comentários

A implementação padrão carrega a legenda da página e tenta determinar o tamanho da página do recurso da caixa de diálogo. Substituir essa função se sua página de propriedades exigir nenhuma providência; sua substituição deve chamar a implementação de classe base.

##  <a name="setcontrolstatus"></a>  COlePropertyPage::SetControlStatus

Altera o status de um controle de página de propriedade.

```
BOOL SetControlStatus(
    UINT nID,
    BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Contém a ID de um controle de página de propriedade.

*bDirty*<br/>
Especifica se um campo da página de propriedades foi modificado. Defina como TRUE se o campo tiver sido modificado, FALSO se não tiver sido modificado.

### <a name="return-value"></a>Valor de retorno

TRUE se o controle especificado tiver sido definido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o status de um controle de página de propriedades está sujo quando a página de propriedades é fechada ou no botão Aplicar for escolhido, a propriedade do controle será atualizada com o valor apropriado.

##  <a name="setdialogresource"></a>  COlePropertyPage::SetDialogResource

Define o recurso de caixa de diálogo da página de propriedades.

```
void SetDialogResource(HGLOBAL hDialog);
```

### <a name="parameters"></a>Parâmetros

*hDialog*<br/>
Identificador para o recurso de caixa de diálogo da página de propriedades.

##  <a name="sethelpinfo"></a>  COlePropertyPage::SetHelpInfo

Especifica o contexto de ajuda para sua página de propriedades, o nome do arquivo de Ajuda e informações de dica de ferramenta.

```
void SetHelpInfo(
    LPCTSTR lpszDocString,
    LPCTSTR lpszHelpFile = NULL,
    DWORD dwHelpContext = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszDocString*<br/>
Uma cadeia de caracteres que contém informações de ajuda breve para exibição em uma barra de status ou em outro local.

*lpszHelpFile*<br/>
Nome do arquivo de Ajuda da página de propriedades.

*dwHelpContext*<br/>
Contexto de ajuda para a página de propriedades.

##  <a name="setmodifiedflag"></a>  COlePropertyPage::SetModifiedFlag

Indica se o usuário modificou a página de propriedades.

```
void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModified*<br/>
Especifica o novo valor do sinalizador de modificado da página de propriedades.

##  <a name="setpagename"></a>  COlePropertyPage::SetPageName

Define o nome da página de propriedades, que o quadro de propriedades normalmente será exibido na guia da página.

```
void SetPageName(LPCTSTR lpszPageName);
```

### <a name="parameters"></a>Parâmetros

*lpszPageName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome da página de propriedades.

## <a name="see-also"></a>Consulte também

[CIRC3 de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC TESTHELP](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
