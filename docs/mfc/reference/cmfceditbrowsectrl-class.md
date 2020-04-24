---
title: Classe CMFCEditBrowseCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCEditBrowseCtrl
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::EnableBrowseButton
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::EnableFileBrowseButton
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::EnableFolderBrowseButton
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::GetMode
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::OnAfterUpdate
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::OnBrowse
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::OnChangeLayout
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::OnDrawBrowseButton
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::OnIllegalFileName
- AFXEDITBROWSECTRL/CMFCEditBrowseCtrl::SetBrowseButtonImage
helpviewer_keywords:
- CMFCEditBrowseCtrl [MFC], EnableBrowseButton
- CMFCEditBrowseCtrl [MFC], EnableFileBrowseButton
- CMFCEditBrowseCtrl [MFC], EnableFolderBrowseButton
- CMFCEditBrowseCtrl [MFC], GetMode
- CMFCEditBrowseCtrl [MFC], OnAfterUpdate
- CMFCEditBrowseCtrl [MFC], OnBrowse
- CMFCEditBrowseCtrl [MFC], OnChangeLayout
- CMFCEditBrowseCtrl [MFC], OnDrawBrowseButton
- CMFCEditBrowseCtrl [MFC], OnIllegalFileName
- CMFCEditBrowseCtrl [MFC], SetBrowseButtonImage
ms.assetid: 69cfd886-3d35-4bee-8901-7c88fcf9520f
ms.openlocfilehash: d542af4a87b6f0a33c0344d1d3da76980f8c1a91
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81752374"
---
# <a name="cmfceditbrowsectrl-class"></a>Classe CMFCEditBrowseCtrl

A `CMFCEditBrowseCtrl` classe suporta o controle de navegação de edição, que é uma caixa de texto editável que contém opcionalmente um botão de navegação. Quando o usuário clica no botão de navegação, o controle executa uma ação personalizada ou exibe uma caixa de diálogo padrão que contém um navegador de arquivos ou um navegador de pasta.

## <a name="syntax"></a>Sintaxe

```
class CMFCEditBrowseCtrl : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCEditBrowseCtrl::CMFCEditBrowseCtrl`|Construtor padrão.|
|`CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCEditBrowseCtrl:EnableBrowseButton](#enablebrowsebutton)|Ativa ou desativa (oculta) o botão de navegação.|
|[CMFCEditBrowseCtrl:EnableFileBrowseButton](#enablefilebrowsebutton)|Habilita o botão de navegação e coloca o controle de navegação de edição no modo *de navegação de arquivos.*|
|[CMFCEditBrowseCtrl:EnableFolderBrowseButton](#enablefolderbrowsebutton)|Habilita o botão de navegação e coloca o controle de navegação de edição no modo *de navegação da pasta.*|
|[CMFCEditBrowseCtrl::GetMode](#getmode)|Retorna o modo de navegação atual.|
|[CMFCEditBrowseCtrl::OnAfterUpdate](#onafterupdate)|Chamado pelo framework após o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.|
|[CMFCEditBrowseCtrl::OnBrowse](#onbrowse)|Chamado pelo framework depois que o usuário clica no botão de navegação.|
|[CMFCEditBrowseCtrl::OnChangeLayout](#onchangelayout)|Redesenha o controle de navegação de edição atual.|
|[CMFCEditBrowseCtrl::OnDrawBrowseButton](#ondrawbrowsebutton)|Chamado pelo framework para desenhar o botão de navegação.|
|[CMFCEditBrowseCtrl::OnIllegalFileName](#onillegalfilename)|Chamado pela estrutura quando um nome de arquivo ilegal foi inserido no controle de edição.|
|`CMFCEditBrowseCtrl::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. Para obter sintaxe e mais informações, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).|
|[CMFCEditBrowseCtrl::SetBrowseButtonImage](#setbrowsebuttonimage)|Define uma imagem personalizada para o botão de navegação.|

## <a name="remarks"></a>Comentários

Use um controle de navegação de edição para selecionar um nome de arquivo ou pasta. Opcionalmente, use o controle para executar uma ação personalizada, como exibir uma caixa de diálogo. Você pode exibir ou não exibir o botão de navegação, e você pode aplicar uma etiqueta ou imagem personalizada no botão.

O modo de *navegação* do controle de navegação de edição determina se ele exibe um botão de navegação e qual ação ocorre quando o botão é clicado. Para obter mais informações, consulte o método [GetMode.](#getmode)

A `CMFCEditBrowseCtrl` classe suporta os seguintes modos.

- **modo personalizado**

   Uma ação personalizada é realizada quando o usuário clica no botão de navegação. Por exemplo, você pode exibir uma caixa de diálogo específica do aplicativo.

- **modo de arquivo**

   Uma caixa de diálogo de seleção de arquivos padrão é exibida quando o usuário clica no botão de navegação.

- **modo pasta**

   Uma caixa de diálogo de seleção de pasta padrão é exibida quando o usuário clica no botão de navegação.

## <a name="how-to-specify-an-edit-browse-control"></a>Como fazer: especificar um controle de navegação de edição

Execute as seguintes etapas para incorporar um controle de navegação de edição em seu aplicativo:

1. Se você quiser implementar um modo de navegação `CMFCEditBrowseCtrl` personalizado, obtenha sua própria classe da classe e, em seguida, anule o método [CMFCEditBrowseCtrl::OnBrowse.](#onbrowse) No método substituído, execute uma ação de navegação personalizada e atualize o controle de navegação de edição com o resultado.

1. Incorporar o `CMFCEditBrowseCtrl` objeto ou o objeto de navegação de edição derivado no objeto de controle da janela pai.

1. Se você usar o **Assistente de Classe** para criar `CEdit`uma caixa de diálogo, adicione um controle de edição ( ) à forma caixa de diálogo. Além disso, adicione uma variável para acessar o controle em seu arquivo de cabeçalho. No seu arquivo de cabeçalho, `CEdit` `CMFCEditBrowseCtrl`altere o tipo da variável de . O controle de navegação de edição será criado automaticamente. Se você não usar o Assistente `CMFCEditBrowseCtrl` de **Classe,** adicione uma `Create` variável ao seu arquivo de cabeçalho e, em seguida, chame seu método.

1. Se você adicionar um controle de navegação de edição a uma caixa de diálogo, use a ferramenta **ClassWizard** para configurar a troca de dados.

1. Ligue para o [método EnableFolderBrowseButton](#enablefolderbrowsebutton), [EnableFileBrowseButton](#enablefilebrowsebutton)ou [EnableBrowseButton](#enablebrowsebutton) para definir o modo de navegação e exibir o botão de navegação. Ligue para o método [GetMode](#getmode) para obter o modo de navegação atual.

1. Para fornecer uma imagem personalizada para o botão de navegação, chame o método [SetBrowseButtonImage](#setbrowsebuttonimage) ou anule o método [OnDrawBrowseButton.](#ondrawbrowsebutton)

1. Para remover o botão de navegação do controle de navegação de edição, chame o método [EnableBrowseButton](#enablebrowsebutton) com o parâmetro *bEnable* definido como FALSE.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

[Cmfceditbrowsectrl](../../mfc/reference/cmfceditbrowsectrl-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCEditBrowseCtrl` usar `EnableFolderBrowseButton` dois `EnableFileBrowseButton`métodos na classe: e . Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#6](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#7](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxeditbrowsectrl.h

## <a name="cmfceditbrowsectrlenablebrowsebutton"></a><a name="enablebrowsebutton"></a>CMFCEditBrowseCtrl:EnableBrowseButton

Exibe ou não o botão de navegação no controle de navegação de edição atual.

```cpp
void EnableBrowseButton(
    BOOL bEnable=TRUE,
    LPCTSTR szLabel=_T("..."));
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
TRUE para exibir o botão de navegação; FALSO para não exibir o botão de navegação. O valor padrão é TRUE.

*szLabel*<br/>
A etiqueta que é exibida no botão de navegação. O valor padrão é " **...**".

### <a name="remarks"></a>Comentários

Se o parâmetro *bEnable* for TRUE, implemente uma ação personalizada para executar quando o botão de navegação for clicado. Para implementar uma ação personalizada, `CMFCEditBrowseCtrl` obtenha uma classe da classe e, em seguida, anule seu método [OnBrowse.](#onbrowse)

Se o parâmetro *bEnable* for TRUE, o `BrowseMode_Default`modo de navegação do controle será ; caso contrário, o `BrowseMode_None`modo de navegação é . Para obter mais informações sobre os modos de navegação, consulte o método [GetMode.](#getmode)

## <a name="cmfceditbrowsectrlenablefilebrowsebutton"></a><a name="enablefilebrowsebutton"></a>CMFCEditBrowseCtrl:EnableFileBrowseButton

Exibe o botão de navegação no controle de navegação de edição atual e coloca o controle no modo *de navegação de arquivo.*

```cpp
void EnableFileBrowseButton(
    LPCTSTR lpszDefExt=NULL,
    LPCTSTR lpszFilter=NULL,
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT);
```

### <a name="parameters"></a>Parâmetros

*lpszDefExt*<br/>
Especifica a extensão de nome de arquivo padrão que é usada na caixa de diálogo de seleção de arquivos. O valor padrão é NULL.

*lpszFilter*<br/>
Especifica a seqüência de filtro padrão usada na caixa de diálogo de seleção de arquivos. O valor padrão é NULL.

*dwFlags*<br/>
Bandeiras da caixa de diálogo. O valor padrão é uma combinação bitwise (OR) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição estiver no modo de navegação de arquivos e o usuário clicar no botão de navegação, o controle exibe a caixa de diálogo de seleção de arquivos padrão.

Para obter uma lista completa de sinalizadores disponíveis, consulte [a estrutura OPENFILENAME](/windows/win32/api/commdlg/ns-commdlg-openfilenamew).

## <a name="cmfceditbrowsectrlenablefolderbrowsebutton"></a><a name="enablefolderbrowsebutton"></a>CMFCEditBrowseCtrl:EnableFolderBrowseButton

Exibe o botão de navegação no controle de navegação de edição atual e coloca o controle no modo *de navegação da pasta.*

```cpp
void EnableFolderBrowseButton();
```

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição estiver no modo de navegação da pasta e o usuário clicar no botão procurar, o controle exibe a caixa de diálogo de seleção de pasta padrão.

## <a name="cmfceditbrowsectrlgetmode"></a><a name="getmode"></a>CMFCEditBrowseCtrl::GetMode

Recupera o modo de navegação do controle de navegação de edição atual.

```
CMFCEditBrowseCtrl::BrowseMode GetMode() const;
```

### <a name="return-value"></a>Valor retornado

Um dos valores de enumeração que especifica o modo atual do controle de navegação de edição. O modo de navegação determina se a estrutura exibe o botão de navegação e qual ação ocorre quando um usuário clica nesse botão.

A tabela a seguir lista os possíveis valores de retorno.

|Valor|Descrição|
|-----------|-----------------|
|`BrowseMode_Default`|**modo personalizado**. Uma ação definida pelo programar é realizada.|
|`BrowseMode_File`|**modo de arquivo**. A caixa de diálogo padrão do navegador de arquivos é exibida.|
|`BrowseMode_Folder`|**modo pasta**. A caixa de diálogo do navegador da pasta padrão é exibida.|
|`BrowseMode_None`|O botão de navegação não é exibido.|

### <a name="remarks"></a>Comentários

Por padrão, `CMFCEditBrowseCtrl` um objeto `BrowseMode_None` é inicializado para o modo. Modifique o modo de navegação com os métodos [CMFCEditBrowseCtrl::EnableBrowseButton,](#enablebrowsebutton) [CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton)e [CMFCEditBrowseCtrl:EnableFolderBrowseButton](#enablefolderbrowsebutton) methods.

## <a name="cmfceditbrowsectrlonafterupdate"></a><a name="onafterupdate"></a>CMFCEditBrowseCtrl::OnAfterUpdate

Chamado pelo framework após o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.

```
virtual void OnAfterUpdate();
```

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar uma ação personalizada.

## <a name="cmfceditbrowsectrlonbrowse"></a><a name="onbrowse"></a>CMFCEditBrowseCtrl::OnBrowse

Chamado pelo framework depois que o usuário clica no botão de navegação do controle de navegação de edição.

```
virtual void OnBrowse();
```

### <a name="remarks"></a>Comentários

Use este método para executar código personalizado quando o usuário clicar no botão de navegação do controle de navegação editar. Obtenha sua própria `CMFCEditBrowseCtrl` classe da classe `OnBrowse` e anule seu método. Nesse método, implemente uma ação de navegação personalizada e, opcionalmente, atualize a caixa de texto do controle de navegação de edição. Em seu aplicativo, use o método [EnableBrowseButton](#enablebrowsebutton) para colocar o controle de navegação de edição no modo *de navegação personalizado.*

## <a name="cmfceditbrowsectrlonchangelayout"></a><a name="onchangelayout"></a>CMFCEditBrowseCtrl::OnChangeLayout

Redesenha o controle de navegação de edição atual.

```
virtual void OnChangeLayout();
```

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando o modo de navegação do controle de navegação de edição é alterado. Para obter mais informações, consulte [CMFCEditBrowseCtrl::GetMode](#getmode).

## <a name="cmfceditbrowsectrlondrawbrowsebutton"></a><a name="ondrawbrowsebutton"></a>CMFCEditBrowseCtrl::OnDrawBrowseButton

Chamado pelo framework para desenhar o botão de navegação no controle de navegação de edição.

```
virtual void OnDrawBrowseButton(
    CDC* pDC,
    CRect rect,
    BOOL bIsButtonPressed,
    BOOL bIsButtonHot);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
O retângulo delimitador do botão de navegação.

*bIsButtonpressed*<br/>
TRUE se o botão for pressionado; caso contrário, FALSE.

*bIsButtonHot*<br/>
TRUE se o botão for destacado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Anular esta função em uma classe derivada para personalizar a aparência do botão de navegação.

## <a name="cmfceditbrowsectrlsetbrowsebuttonimage"></a><a name="setbrowsebuttonimage"></a>CMFCEditBrowseCtrl::SetBrowseButtonImage

Define uma imagem personalizada no botão de navegação do controle de navegação de edição.

```cpp
void SetBrowseButtonImage(
    HICON hIcon,
    BOOL bAutoDestroy= TRUE);

void SetBrowseButtonImage(
    HBITMAP hBitmap,
    BOOL bAutoDestroy= TRUE);

void SetBrowseButtonImage(UINT uiBmpResId);
```

### <a name="parameters"></a>Parâmetros

*Hicon*<br/>
A alça de um ícone.

*Hbitmap*<br/>
A alça de um bitmap.

*uiBmpResId*<br/>
O ID de recurso de um bitmap.

*bAutoDestroy*<br/>
TRUE para excluir o ícone ou bitmap especificado quando este método sair; caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use este método para aplicar uma imagem personalizada ao botão de navegação. Por padrão, a estrutura obtém uma imagem padrão quando o controle de navegação de edição está no modo *de navegação de arquivo* ou de navegação de *pasta.*

## <a name="cmfceditbrowsectrlonillegalfilename"></a><a name="onillegalfilename"></a>CMFCEditBrowseCtrl::OnIllegalFileName

Chamado pela estrutura quando um nome de arquivo ilegal foi inserido no controle de edição.

```
virtual BOOL OnIllegalFileName(CString& strFileName);
```

### <a name="parameters"></a>Parâmetros

*Strfilename*<br/>
Especifica o nome do arquivo ilegal.

### <a name="return-value"></a>Valor retornado

Deve retornar FALSE se este nome de arquivo não puder ser passado mais adiante para a caixa de diálogo do arquivo. Neste caso, o foco é definido de volta para o controle de edição e o usuário deve continuar editando. A implementação padrão exibe uma caixa de mensagem indique ao usuário sobre o nome do arquivo ilegal e retorna FALSO. Você pode substituir este método, corrigir o nome do arquivo e retornar TRUE para posterior processamento.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
