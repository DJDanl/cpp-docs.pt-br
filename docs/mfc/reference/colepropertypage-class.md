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
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421089"
---
# <a name="colepropertypage-class"></a>Classe COlePropertyPage

Usado para exibir as propriedades de um controle personalizado em uma interface gráfica, semelhante a uma caixa de diálogo.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE COlePropertyPage : public CDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COlePropertyPage:: COlePropertyPage](#colepropertypage)|Constrói um objeto `COlePropertyPage`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COlePropertyPage:: GetControlStatus](#getcontrolstatus)|Indica se o usuário modificou o valor no controle.|
|[COlePropertyPage:: GetObjectArray](#getobjectarray)|Retorna a matriz de objetos que estão sendo editados pela página de propriedades.|
|[COlePropertyPage:: GetPageSite](#getpagesite)|Retorna um ponteiro para a interface de `IPropertyPageSite` da página de propriedades.|
|[COlePropertyPage:: IgnoreApply](#ignoreapply)|Determina quais controles não habilitam o botão Aplicar.|
|[COlePropertyPage:: IsModified](#ismodified)|Indica se o usuário modificou a página de propriedades.|
|[COlePropertyPage:: oneditproperty](#oneditproperty)|Chamado pelo Framework quando o usuário edita uma propriedade.|
|[COlePropertyPage:: OnHelp](#onhelp)|Chamado pelo Framework quando o usuário chama a ajuda.|
|[COlePropertyPage:: OnInitDialog](#oninitdialog)|Chamado pelo Framework quando a página de propriedades é inicializada.|
|[COlePropertyPage:: onobjects](#onobjectschanged)|Chamado pelo Framework quando outro controle OLE, com novas propriedades, é escolhido.|
|[COlePropertyPage:: OnSetPageSite](#onsetpagesite)|Chamado pelo Framework quando o quadro de propriedades fornece o site da página.|
|[COlePropertyPage:: SetControlStatus](#setcontrolstatus)|Define um sinalizador que indica se o usuário modificou o valor no controle.|
|[COlePropertyPage:: SetDialogResource](#setdialogresource)|Define o recurso de caixa de diálogo da página de propriedades.|
|[COlePropertyPage:: SetHelpInfo](#sethelpinfo)|Define o texto de ajuda breve da página de propriedades, o nome do seu arquivo de ajuda e seu contexto de ajuda.|
|[COlePropertyPage:: SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica se o usuário modificou a página de propriedades.|
|[COlePropertyPage:: setpagename](#setpagename)|Define o nome da página de Propriedades (legenda).|

## <a name="remarks"></a>Comentários

Por exemplo, uma página de propriedades pode incluir um controle de edição que permite ao usuário exibir e modificar a propriedade de legenda do controle.

Cada propriedade personalizada ou de controle de estoque pode ter um controle de caixa de diálogo que permite ao usuário do controle exibir o valor da propriedade atual e modificar esse valor, se necessário.

Para obter mais informações sobre como usar `COlePropertyPage`, consulte o artigo [controles ActiveX: páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

`COlePropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="colepropertypage"></a>COlePropertyPage:: COlePropertyPage

Constrói um objeto `COlePropertyPage`.

```
COlePropertyPage(
    UINT idDlg,
    UINT idCaption);
```

### <a name="parameters"></a>parâmetros

*idDlg*<br/>
ID de recurso do modelo de caixa de diálogo.

*idCaption*<br/>
ID de recurso da legenda da página de propriedades.

### <a name="remarks"></a>Comentários

Quando você implementa uma subclasse de `COlePropertyPage`, o construtor de sua subclasse deve usar o Construtor `COlePropertyPage` para identificar o recurso de modelo de caixa de diálogo no qual a página de propriedades é baseada e o recurso de cadeia de caracteres que contém sua legenda.

##  <a name="getcontrolstatus"></a>COlePropertyPage:: GetControlStatus

Determina se o usuário modificou o valor do controle de página de propriedades com a ID de recurso especificada.

```
BOOL GetControlStatus(UINT nID);
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
ID de recurso de um controle de página de propriedades.

### <a name="return-value"></a>Valor retornado

TRUE se o valor de controle tiver sido modificado; caso contrário, FALSE.

##  <a name="getobjectarray"></a>COlePropertyPage:: GetObjectArray

Retorna a matriz de objetos que estão sendo editados pela página de propriedades.

```
LPDISPATCH* GetObjectArray(ULONG* pnObjects);
```

### <a name="parameters"></a>parâmetros

*pnObjects*<br/>
Ponteiro para um inteiro longo sem sinal que receberá o número de objetos que estão sendo editados pela página.

### <a name="return-value"></a>Valor retornado

Ponteiro para uma matriz de ponteiros de `IDispatch`, que são usados para acessar as propriedades de cada controle na página de propriedades. O chamador não deve liberar esses ponteiros de interface.

### <a name="remarks"></a>Comentários

Cada objeto da página de propriedades mantém uma matriz de ponteiros para as interfaces `IDispatch` dos objetos que estão sendo editados pela página. Essa função define seu argumento *pnObjects* como o número de elementos nessa matriz e retorna um ponteiro para o primeiro elemento da matriz.

##  <a name="getpagesite"></a>COlePropertyPage:: GetPageSite

Obtém um ponteiro para a interface de `IPropertyPageSite` da página de propriedades.

```
LPPROPERTYPAGESITE GetPageSite();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface de `IPropertyPageSite` da página de propriedades.

### <a name="remarks"></a>Comentários

Controles e contêineres cooperam para que os usuários possam procurar e editar propriedades de controle. O controle fornece páginas de propriedades, cada uma delas é um objeto OLE que permite ao usuário editar um conjunto de propriedades relacionado. O contêiner fornece um quadro de propriedades que exibe as páginas de propriedades. Para cada página, o quadro de propriedades fornece um site de página, que dá suporte à interface `IPropertyPageSite`.

##  <a name="ignoreapply"></a>COlePropertyPage:: IgnoreApply

Determina quais controles não habilitam o botão Aplicar.

```
void IgnoreApply(UINT nID);
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
ID do controle a ser ignorado.

### <a name="remarks"></a>Comentários

O botão aplicar da página de propriedades é habilitado somente quando os valores dos controles da página de propriedades foram alterados. Use essa função para especificar controles que não fazem com que o botão Aplicar seja habilitado quando seus valores forem alterados.

##  <a name="ismodified"></a>COlePropertyPage:: IsModified

Determina se o usuário alterou qualquer valor na página de propriedades.

```
BOOL IsModified();
```

### <a name="return-value"></a>Valor retornado

TRUE se a página de propriedades tiver sido modificada.

##  <a name="oneditproperty"></a>COlePropertyPage:: oneditproperty

A estrutura chama essa função quando uma propriedade específica deve ser editada.

```
virtual BOOL OnEditProperty(DISPID dispid);
```

### <a name="parameters"></a>parâmetros

*DISPID*<br/>
ID de expedição da propriedade que está sendo editada.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE. As substituições dessa função devem retornar TRUE.

### <a name="remarks"></a>Comentários

Você pode substituí-lo para definir o foco para o controle apropriado na página. A implementação padrão não faz nada e retorna FALSE.

##  <a name="onhelp"></a>COlePropertyPage:: OnHelp

A estrutura chama essa função quando o usuário solicita ajuda online.

```
virtual BOOL OnHelp(LPCTSTR lpszHelpDir);
```

### <a name="parameters"></a>parâmetros

*lpszHelpDir*<br/>
Diretório que contém o arquivo de ajuda da página de propriedades.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE.

### <a name="remarks"></a>Comentários

Substitua-o se a sua página de propriedades precisar executar qualquer ação especial quando o usuário acessar a ajuda. A implementação padrão não faz nada e retorna FALSE, que instrui o Framework a chamar o WinHelp.

##  <a name="oninitdialog"></a>COlePropertyPage:: OnInitDialog

A estrutura chama essa função quando a caixa de diálogo da página de propriedades é inicializada.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE.

### <a name="remarks"></a>Comentários

Substitua-o se alguma ação especial for necessária quando a caixa de diálogo for inicializada. A implementação padrão chama `CDialog::OnInitDialog` e retorna FALSE.

##  <a name="onobjectschanged"></a>COlePropertyPage:: onobjects

Chamado pelo Framework quando outro controle OLE, com novas propriedades, é escolhido.

```
virtual void OnObjectsChanged();
```

### <a name="remarks"></a>Comentários

Ao exibir as propriedades de um controle OLE no ambiente do desenvolvedor, uma caixa de diálogo sem janela restrita é usada para exibir suas páginas de propriedades. Se outro controle for selecionado, um conjunto diferente de páginas de propriedades deverá ser exibido para o novo conjunto de propriedades. A estrutura chama essa função para notificar a página de propriedades da alteração.

Substitua essa função para receber a notificação dessa ação e executar ações especiais.

##  <a name="onsetpagesite"></a>COlePropertyPage:: OnSetPageSite

A estrutura chama essa função quando o quadro de propriedades fornece o site da página da página de propriedades.

```
virtual void OnSetPageSite();
```

### <a name="remarks"></a>Comentários

A implementação padrão carrega a legenda da página e tenta determinar o tamanho da página a partir do recurso de caixa de diálogo. Substitua esta função se sua página de propriedades exigir qualquer ação adicional; sua substituição deve chamar a implementação da classe base.

##  <a name="setcontrolstatus"></a>COlePropertyPage:: SetControlStatus

Altera o status de um controle de página de propriedades.

```
BOOL SetControlStatus(
    UINT nID,
    BOOL bDirty);
```

### <a name="parameters"></a>parâmetros

*nID*<br/>
Contém a ID de um controle de página de propriedades.

*bDirty*<br/>
Especifica se um campo da página de propriedades foi modificado. Defina como TRUE se o campo tiver sido modificado, FALSE se ele não tiver sido modificado.

### <a name="return-value"></a>Valor retornado

TRUE, se o controle especificado tiver sido definido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o status de um controle de página de Propriedades for sujo quando a página de Propriedades for fechada ou o botão Aplicar for escolhido, a propriedade do controle será atualizada com o valor apropriado.

##  <a name="setdialogresource"></a>COlePropertyPage:: SetDialogResource

Define o recurso de caixa de diálogo da página de propriedades.

```
void SetDialogResource(HGLOBAL hDialog);
```

### <a name="parameters"></a>parâmetros

*hDialog*<br/>
Identificador para o recurso de caixa de diálogo da página de propriedades.

##  <a name="sethelpinfo"></a>COlePropertyPage:: SetHelpInfo

Especifica informações de dica de ferramenta, o nome de arquivo da ajuda e o contexto da ajuda para sua página de propriedades.

```
void SetHelpInfo(
    LPCTSTR lpszDocString,
    LPCTSTR lpszHelpFile = NULL,
    DWORD dwHelpContext = 0);
```

### <a name="parameters"></a>parâmetros

*lpszDocString*<br/>
Uma cadeia de caracteres que contém informações de breve ajuda para exibição em uma barra de status ou em outro local.

*lpszHelpFile*<br/>
Nome do arquivo de ajuda da página de propriedades.

*dwHelpContext*<br/>
Contexto de ajuda para a página de propriedades.

##  <a name="setmodifiedflag"></a>COlePropertyPage:: SetModifiedFlag

Indica se o usuário modificou a página de propriedades.

```
void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>parâmetros

*bModified*<br/>
Especifica o novo valor para o sinalizador modificado da página de propriedades.

##  <a name="setpagename"></a>COlePropertyPage:: setpagename

Define o nome da página de propriedades, que o quadro de propriedades normalmente exibirá na guia da página.

```
void SetPageName(LPCTSTR lpszPageName);
```

### <a name="parameters"></a>parâmetros

*lpszPageName*<br/>
Ponteiro para uma cadeia de caracteres que contém o nome da página de propriedades.

## <a name="see-also"></a>Confira também

[Exemplo de CIRC3 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de TESTHELP do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
