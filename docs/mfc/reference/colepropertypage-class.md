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
ms.openlocfilehash: dbdc889e244b33365756bcbae5b37cf657a6d900
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374876"
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
|[COlePropertyPage::GetControlStatus](#getcontrolstatus)|Indica se o usuário modificou o valor no controle.|
|[COlePropertyPage::GetObjectArray](#getobjectarray)|Retorna a matriz de objetos que estão sendo editados pela página de propriedade.|
|[COlePropertyPage::GetPageSite](#getpagesite)|Retorna um ponteiro para a `IPropertyPageSite` interface da página de propriedade.|
|[COlePropertyPage::IgnoreApply](#ignoreapply)|Determina quais controles não ativam o botão Aplicar.|
|[COlePropertyPage::IsModified](#ismodified)|Indica se o usuário modificou a página da propriedade.|
|[COlePropertyPage::OnEditProperty](#oneditproperty)|Chamado pela estrutura quando o usuário emite uma propriedade.|
|[COlePropertyPage::OnHelp](#onhelp)|Chamado pela estrutura quando o usuário invoca ajuda.|
|[COlePropertyPage::OnInitDialog](#oninitdialog)|Chamado pela estrutura quando a página de propriedade é inicializada.|
|[COlePropertyPage::OnObjectsChanged](#onobjectschanged)|Chamado pela estrutura quando outro controle OLE, com novas propriedades, é escolhido.|
|[COlePropertyPage::OnSetPageSite](#onsetpagesite)|Chamado pela estrutura quando o quadro de propriedade fornece o site da página.|
|[COlePropertyPage::SetControlStatus](#setcontrolstatus)|Define uma bandeira indicando se o usuário modificou o valor no controle.|
|[COlePropertyPage::SetDialogResource](#setdialogresource)|Define o recurso de diálogo da página de propriedade.|
|[COlePropertyPage::SetHelpInfo](#sethelpinfo)|Define o texto de ajuda breve da página de propriedade, o nome de seu arquivo de ajuda e seu contexto de ajuda.|
|[COlePropertyPage::SetModifiedFlag](#setmodifiedflag)|Define um sinalizador indicando se o usuário modificou a página da propriedade.|
|[COlePropertyPage::SetPageName](#setpagename)|Define o nome da página de propriedade (legenda).|

## <a name="remarks"></a>Comentários

Por exemplo, uma página de propriedade pode incluir um controle de edição que permite ao usuário visualizar e modificar a propriedade de legenda do controle.

Cada propriedade personalizada ou de controle de estoque pode ter um controle de diálogo que permite ao usuário do controle visualizar o valor atual da propriedade e modificar esse valor, se necessário.

Para obter mais `COlePropertyPage`informações sobre o uso, consulte o artigo [ActiveX Controls: Property Pages](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

`COlePropertyPage`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="colepropertypagecolepropertypage"></a><a name="colepropertypage"></a>COlePropertyPage::COlePropertyPage

Constrói um objeto `COlePropertyPage`.

```
COlePropertyPage(
    UINT idDlg,
    UINT idCaption);
```

### <a name="parameters"></a>Parâmetros

*IdDlg*<br/>
ID de recurso do modelo de diálogo.

*idCaption*<br/>
ID de recurso da legenda da página de propriedade.

### <a name="remarks"></a>Comentários

Quando você implementa `COlePropertyPage`uma subclasse de , o `COlePropertyPage` construtor da subclasse deve usar o construtor para identificar o recurso de modelo de diálogo no qual a página de propriedade é baseada e o recurso string contendo sua legenda.

## <a name="colepropertypagegetcontrolstatus"></a><a name="getcontrolstatus"></a>COlePropertyPage::GetControlStatus

Determina se o usuário modificou o valor do controle da página de propriedade com o ID de recurso especificado.

```
BOOL GetControlStatus(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID de recurso de um controle de página de propriedade.

### <a name="return-value"></a>Valor retornado

TRUE se o valor de controle tiver sido modificado; caso contrário, FALSO.

## <a name="colepropertypagegetobjectarray"></a><a name="getobjectarray"></a>COlePropertyPage::GetObjectArray

Retorna a matriz de objetos que estão sendo editados pela página de propriedade.

```
LPDISPATCH* GetObjectArray(ULONG* pnObjects);
```

### <a name="parameters"></a>Parâmetros

*pnObjects*<br/>
Ponteiro para um inteiro longo não assinado que receberá o número de objetos que estão sendo editados pela página.

### <a name="return-value"></a>Valor retornado

Ponteiro para uma `IDispatch` matriz de ponteiros, que são usados para acessar as propriedades de cada controle na página da propriedade. O chamador não deve liberar esses ponteiros de interface.

### <a name="remarks"></a>Comentários

Cada objeto de página de propriedade `IDispatch` mantém uma matriz de ponteiros para as interfaces dos objetos que estão sendo editados pela página. Esta função define seu argumento *pnObjects* para o número de elementos nessa matriz e retorna um ponteiro para o primeiro elemento da matriz.

## <a name="colepropertypagegetpagesite"></a><a name="getpagesite"></a>COlePropertyPage::GetPageSite

Obtém um ponteiro para `IPropertyPageSite` a interface da página de propriedade.

```
LPPROPERTYPAGESITE GetPageSite();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a `IPropertyPageSite` interface da página de propriedade.

### <a name="remarks"></a>Comentários

Controles e contêineres cooperam para que os usuários possam navegar e editar propriedades de controle. O controle fornece páginas de propriedade, cada uma delas é um objeto OLE que permite ao usuário editar um conjunto de propriedades relacionados. O contêiner fornece um quadro de propriedade que exibe as páginas da propriedade. Para cada página, o quadro de propriedades fornece `IPropertyPageSite` um site de página, que suporta a interface.

## <a name="colepropertypageignoreapply"></a><a name="ignoreapply"></a>COlePropertyPage::IgnoreApply

Determina quais controles não ativam o botão Aplicar.

```
void IgnoreApply(UINT nID);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
ID do controle a ser ignorado.

### <a name="remarks"></a>Comentários

O botão Aplicar da página de propriedade é ativado somente quando os valores dos controles da página de propriedade foram alterados. Use esta função para especificar controles que não fazem com que o botão Aplicar seja ativado quando seus valores mudarem.

## <a name="colepropertypageismodified"></a><a name="ismodified"></a>COlePropertyPage::IsModified

Determina se o usuário alterou algum valor na página da propriedade.

```
BOOL IsModified();
```

### <a name="return-value"></a>Valor retornado

TRUE se a página de propriedade foi modificada.

## <a name="colepropertypageoneditproperty"></a><a name="oneditproperty"></a>COlePropertyPage::OnEditProperty

O framework chama essa função quando uma propriedade específica deve ser editada.

```
virtual BOOL OnEditProperty(DISPID dispid);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
Despachar a id da propriedade que está sendo editada.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE. As substituições desta função devem retornar TRUE.

### <a name="remarks"></a>Comentários

Você pode substituí-lo para definir o foco para o controle apropriado na página. A implementação padrão não faz nada e retorna FALSE.

## <a name="colepropertypageonhelp"></a><a name="onhelp"></a>COlePropertyPage::OnHelp

A estrutura chama essa função quando o usuário solicita ajuda on-line.

```
virtual BOOL OnHelp(LPCTSTR lpszHelpDir);
```

### <a name="parameters"></a>Parâmetros

*lpszHelpDir*<br/>
Diretório contendo o arquivo de ajuda da página de propriedade.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE.

### <a name="remarks"></a>Comentários

Anular se sua página de propriedade tiver que executar qualquer ação especial quando o usuário acessar a ajuda. A implementação padrão não faz nada e retorna FALSE, que instrui a estrutura a chamar WinHelp.

## <a name="colepropertypageoninitdialog"></a><a name="oninitdialog"></a>COlePropertyPage::OnInitDialog

O framework chama essa função quando a caixa de diálogo da página de propriedade é inicializada.

```
virtual BOOL OnInitDialog();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna FALSE.

### <a name="remarks"></a>Comentários

Anular-o se for necessária alguma ação especial quando a diálogo for inicializada. A implementação `CDialog::OnInitDialog` padrão chama e retorna FALSO.

## <a name="colepropertypageonobjectschanged"></a><a name="onobjectschanged"></a>COlePropertyPage::OnObjectsChanged

Chamado pela estrutura quando outro controle OLE, com novas propriedades, é escolhido.

```
virtual void OnObjectsChanged();
```

### <a name="remarks"></a>Comentários

Ao visualizar as propriedades de um controle OLE no ambiente do desenvolvedor, uma caixa de diálogo modeless é usada para exibir suas páginas de propriedade. Se outro controle for selecionado, um conjunto diferente de páginas de propriedade deve ser exibido para o novo conjunto de propriedades. O framework chama essa função para notificar a página de propriedade da alteração.

Anular esta função para receber notificação desta ação e realizar quaisquer ações especiais.

## <a name="colepropertypageonsetpagesite"></a><a name="onsetpagesite"></a>COlePropertyPage::OnSetPageSite

O framework chama essa função quando o quadro de propriedade fornece o site da página da página da propriedade.

```
virtual void OnSetPageSite();
```

### <a name="remarks"></a>Comentários

A implementação padrão carrega a legenda da página e tenta determinar o tamanho da página a partir do recurso de diálogo. Anular essa função se a página de propriedade exigir qualquer ação adicional; sua substituição deve chamar a implementação da classe base.

## <a name="colepropertypagesetcontrolstatus"></a><a name="setcontrolstatus"></a>COlePropertyPage::SetControlStatus

Altera o status de um controle de página de propriedade.

```
BOOL SetControlStatus(
    UINT nID,
    BOOL bDirty);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
Contém o ID de um controle de página de propriedade.

*Bdirty*<br/>
Especifica se um campo da página de propriedade foi modificado. Definir como TRUE se o campo tiver sido modificado, FALSO se não tiver sido modificado.

### <a name="return-value"></a>Valor retornado

TRUE, se o controle especificado foi definido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se o status de um controle de página de propriedade estiver sujo quando a página da propriedade estiver fechada ou o botão Aplicar for escolhido, a propriedade do controle será atualizada com o valor apropriado.

## <a name="colepropertypagesetdialogresource"></a><a name="setdialogresource"></a>COlePropertyPage::SetDialogResource

Define o recurso de diálogo da página de propriedade.

```
void SetDialogResource(HGLOBAL hDialog);
```

### <a name="parameters"></a>Parâmetros

*hDialog*<br/>
Manuseie o recurso de diálogo da página de propriedade.

## <a name="colepropertypagesethelpinfo"></a><a name="sethelpinfo"></a>COlePropertyPage::SetHelpInfo

Especifica informações de dica de ferramenta, o nome do arquivo de ajuda e o contexto de ajuda para sua página de propriedade.

```
void SetHelpInfo(
    LPCTSTR lpszDocString,
    LPCTSTR lpszHelpFile = NULL,
    DWORD dwHelpContext = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszDocString*<br/>
Uma seqüência contendo breves informações de ajuda para exibição em uma barra de status ou outro local.

*lpszHelpFile*<br/>
Nome do arquivo de ajuda da página da propriedade.

*dwHelpContext*<br/>
Contexto de ajuda para a página de propriedade.

## <a name="colepropertypagesetmodifiedflag"></a><a name="setmodifiedflag"></a>COlePropertyPage::SetModifiedFlag

Indica se o usuário modificou a página da propriedade.

```
void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModificado*<br/>
Especifica o novo valor para o sinalizador modificado da página de propriedade.

## <a name="colepropertypagesetpagename"></a><a name="setpagename"></a>COlePropertyPage::SetPageName

Define o nome da página de propriedade, que o quadro de propriedade normalmente exibirá na guia da página.

```
void SetPageName(LPCTSTR lpszPageName);
```

### <a name="parameters"></a>Parâmetros

*lpszPageName*<br/>
Ponteiro para uma seqüência contendo o nome da página da propriedade.

## <a name="see-also"></a>Confira também

[MFC Amostra CIRC3](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra TESTHELP](../../overview/visual-cpp-samples.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
