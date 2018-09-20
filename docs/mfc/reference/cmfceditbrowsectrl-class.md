---
title: Classe CMFCEditBrowseCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7abfa802272bf26fbcf581bb2ff77fd0321e4ff2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46397528"
---
# <a name="cmfceditbrowsectrl-class"></a>Classe CMFCEditBrowseCtrl

O `CMFCEditBrowseCtrl` classe dá suporte a controle de navegação de edição, que é uma caixa de texto editável que opcionalmente contém um botão de procura. Quando o usuário clica no botão Procurar, o controle executa uma ação personalizada ou exibe uma caixa de diálogo padrão que contém um navegador de arquivos ou um navegador de pasta.

## <a name="syntax"></a>Sintaxe

```
class CMFCEditBrowseCtrl : public CEdit
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCEditBrowseCtrl::CMFCEditBrowseCtrl`|Construtor padrão.|
|`CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCEditBrowseCtrl::EnableBrowseButton](#enablebrowsebutton)|Habilita ou desabilita (oculta) no botão Procurar.|
|[CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton)|Habilita o botão Procurar e coloca o controle de navegação de edição na *procura arquivo* modo.|
|[CMFCEditBrowseCtrl::EnableFolderBrowseButton](#enablefolderbrowsebutton)|Habilita o botão Procurar e coloca o controle de navegação de edição na *Procurar pasta* modo.|
|[CMFCEditBrowseCtrl::GetMode](#getmode)|Retorna o modo de busca atual.|
|[CMFCEditBrowseCtrl::OnAfterUpdate](#onafterupdate)|Chamado pelo framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.|
|[CMFCEditBrowseCtrl::OnBrowse](#onbrowse)|Chamado pelo framework depois que o usuário clica no botão Procurar.|
|[CMFCEditBrowseCtrl::OnChangeLayout](#onchangelayout)|Redesenha o controle de navegação de edição atual.|
|[CMFCEditBrowseCtrl::OnDrawBrowseButton](#ondrawbrowsebutton)|Chamado pelo framework para desenhar o botão Procurar.|
|[CMFCEditBrowseCtrl::OnIllegalFileName](#onillegalfilename)|Chamado pelo framework quando um nome de arquivo ilegal foi inserido no controle de edição.|
|`CMFCEditBrowseCtrl::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. Para sintaxe e obter mais informações, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).|
|[CMFCEditBrowseCtrl::SetBrowseButtonImage](#setbrowsebuttonimage)|Define uma imagem personalizada para o botão Procurar.|

## <a name="remarks"></a>Comentários

Use um controle de edição Procurar para selecionar um nome de arquivo ou pasta. Opcionalmente, use o controle para executar uma ação personalizada, como exibir uma caixa de diálogo. Você pode exibir ou não exibir o botão Procurar, e você pode aplicar um rótulo personalizado ou uma imagem do botão.

O *modo de procura* de procurar Editar controle determina se ele exibe um botão de procura e a ação que ocorre quando o botão é clicado. Para obter mais informações, consulte o [GetMode](#getmode) método.

O `CMFCEditBrowseCtrl` classe dá suporte a modos a seguir.

- **modo personalizado**

   Uma ação personalizada é executada quando o usuário clica no botão Procurar. Por exemplo, você pode exibir uma caixa de diálogo específicas do aplicativo.

- **modo de arquivo**

   Uma caixa de diálogo de seleção de arquivo padrão é exibida quando o usuário clica no botão Procurar.

- **modo de pasta**

   Uma caixa de diálogo de seleção de pasta padrão é exibida quando o usuário clica no botão Procurar.

## <a name="how-to-specify-an-edit-browse-control"></a>Como: Especificar um controle de navegação de edição

Execute as seguintes etapas para incorporar um controle de edição de procurar em seu aplicativo:

1. Se você quiser implementar um modo de navegação personalizada, derive sua própria classe do `CMFCEditBrowseCtrl` de classe e, em seguida, substituir o [CMFCEditBrowseCtrl::OnBrowse](#onbrowse) método. No método substituído, execute uma ação de navegação personalizada e atualizar o controle de navegação de edição com o resultado.

1. Incorporar qualquer uma de `CMFCEditBrowseCtrl` objeto ou o objeto de controle edição derivada procurar no objeto de janela pai.

1. Se você usar o **Class Wizard** para criar uma caixa de diálogo, adicione um controle de edição ( `CEdit`) para o formulário de caixa de diálogo. Além disso, adicione uma variável para acessar o controle em seu arquivo de cabeçalho. No seu arquivo de cabeçalho, altere o tipo da variável de `CEdit` para `CMFCEditBrowseCtrl`. O controle de navegação de edição será criado automaticamente. Se você não usar o **Class Wizard**, adicione uma `CMFCEditBrowseCtrl` variável ao seu arquivo de cabeçalho e em seguida, chame seu `Create` método.

1. Se você adicionar um controle de navegação de edição para uma caixa de diálogo, use o **ClassWizard** ferramenta para configurar a troca de dados.

1. Chame o [EnableFolderBrowseButton](#enablefolderbrowsebutton), [EnableFileBrowseButton](#enablefilebrowsebutton), ou [EnableBrowseButton](#enablebrowsebutton) método para definir o modo de procura e exibir o botão Procurar. Chame o [GetMode](#getmode) método para obter o modo de busca atual.

1. Para fornecer uma imagem personalizada para o botão Procurar, chame o [SetBrowseButtonImage](#setbrowsebuttonimage) método ou substituição a [OnDrawBrowseButton](#ondrawbrowsebutton) método.

1. Para remover o botão Procurar do controle de navegação de edição, chame o [EnableBrowseButton](#enablebrowsebutton) método com o *bAtivar* parâmetro definido como FALSE.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

[CMFCEditBrowseCtrl](../../mfc/reference/cmfceditbrowsectrl-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar dois métodos de `CMFCEditBrowseCtrl` classe: `EnableFolderBrowseButton` e `EnableFileBrowseButton`. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#6](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#7](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxeditbrowsectrl.h

##  <a name="enablebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableBrowseButton

Exibe ou não exibe o botão Procurar no controle de navegação de edição atual.

```
void EnableBrowseButton(
    BOOL bEnable=TRUE,
    LPCTSTR szLabel=_T("..."));
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
TRUE para exibir o botão de procura; FALSO para não exibir o botão Procurar. O valor padrão é TRUE.

*szLabel*<br/>
O rótulo que é exibido no botão Procurar. O valor padrão é " **...** ".

### <a name="remarks"></a>Comentários

Se o *bAtivar* parâmetro for TRUE, implemente uma ação personalizada para executar quando o botão é clicado. Para implementar uma ação personalizada, derive uma classe do `CMFCEditBrowseCtrl` de classe e, em seguida, substituir seus [OnBrowse](#onbrowse) método.

Se o *bAtivar* parâmetro for TRUE, o modo de procura do controle é `BrowseMode_Default`; caso contrário, o modo de procura é `BrowseMode_None`. Para obter mais informações sobre os modos de procurar, consulte o [GetMode](#getmode) método.

##  <a name="enablefilebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFileBrowseButton

Exibe o botão Procurar no controle de navegação de edição atual e o coloca no *procura arquivo* modo.

```
void EnableFileBrowseButton(
    LPCTSTR lpszDefExt=NULL,
    LPCTSTR lpszFilter=NULL,
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT);
```

### <a name="parameters"></a>Parâmetros

*lpszDefExt*<br/>
Especifica a extensão de nome de arquivo padrão que é usada na caixa de diálogo de seleção de arquivo. O valor padrão é NULL.

*lpszFilter*<br/>
Especifica a cadeia de caracteres de filtro padrão que é usada na caixa de diálogo de seleção de arquivo. O valor padrão é NULL.

*dwFlags*<br/>
Sinalizadores de caixa de diálogo. O valor padrão é uma combinação bit a bit (OR) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição está em modo de procura de arquivo e o usuário clica no botão Procurar, o controle exibe a caixa de diálogo de seleção de arquivo padrão.

Para obter uma lista completa dos sinalizadores disponíveis, consulte [estrutura OPENFILENAME](/windows/desktop/api/commdlg/ns-commdlg-tagofna).

##  <a name="enablefolderbrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFolderBrowseButton

Exibe o botão Procurar no controle de navegação de edição atual e o coloca no *Procurar pasta* modo.

```
void EnableFolderBrowseButton();
```

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição está em modo de procura de pasta e o usuário clica no botão Procurar, o controle exibe a caixa de diálogo de seleção de pasta padrão.

##  <a name="getmode"></a>  CMFCEditBrowseCtrl::GetMode

Recupera o modo de busca do controle de navegação de edição atual.

```
CMFCEditBrowseCtrl::BrowseMode GetMode() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos valores de enumeração que especifica o modo atual da edição procurar o controle. O modo de busca determina se o framework exibe o botão Procurar e a ação que ocorre quando um usuário clica nesse botão.

A tabela a seguir lista os possíveis valores de retorno.

|Valor|Descrição|
|-----------|-----------------|
|`BrowseMode_Default`|**modo personalizado**. Uma ação definida pelo programador é executada.|
|`BrowseMode_File`|**modo de arquivo**. A caixa de diálogo de navegador de arquivo padrão é exibida.|
|`BrowseMode_Folder`|**modo de pasta**. A caixa de diálogo de navegador de pasta padrão é exibida.|
|`BrowseMode_None`|Não é exibido no botão Procurar.|

### <a name="remarks"></a>Comentários

Por padrão, uma `CMFCEditBrowseCtrl` objeto é inicializado como `BrowseMode_None` modo. Modificar o modo de procura com as [CMFCEditBrowseCtrl::EnableBrowseButton](#enablebrowsebutton), [CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton), e [CMFCEditBrowseCtrl::EnableFolderBrowseButton ](#enablefolderbrowsebutton) métodos.

##  <a name="onafterupdate"></a>  CMFCEditBrowseCtrl::OnAfterUpdate

Chamado pelo framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.

```
virtual void OnAfterUpdate();
```

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar uma ação personalizada.

##  <a name="onbrowse"></a>  CMFCEditBrowseCtrl::OnBrowse

Chamado pelo framework depois que o usuário clica no botão Procurar do controle de navegação de edição.

```
virtual void OnBrowse();
```

### <a name="remarks"></a>Comentários

Use esse método para executar código personalizado quando o usuário clica no botão Procurar do controle de navegação de edição. Derivar sua própria classe a partir de `CMFCEditBrowseCtrl` de classe e substituir seu `OnBrowse` método. Nesse método, implementar uma ação de navegação personalizada e, opcionalmente, atualize a caixa de texto do controle de navegação de edição. Em seu aplicativo, use o [EnableBrowseButton](#enablebrowsebutton) método colocar o controle de navegação de edição *navegação personalizada* modo.

##  <a name="onchangelayout"></a>  CMFCEditBrowseCtrl::OnChangeLayout

Redesenha o controle de navegação de edição atual.

```
virtual void OnChangeLayout();
```

### <a name="remarks"></a>Comentários

O framework chama esse método quando o modo de procura de procurar Editar controle de alterações. Para obter mais informações, consulte [CMFCEditBrowseCtrl::GetMode](#getmode).

##  <a name="ondrawbrowsebutton"></a>  CMFCEditBrowseCtrl::OnDrawBrowseButton

Chamado pelo framework para desenhar o botão Procurar no controle de navegação de edição.

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
O retângulo delimitador do botão Procurar.

*bIsButtonPressed*<br/>
TRUE se o botão for pressionado; Caso contrário, FALSE.

*bIsButtonHot*<br/>
TRUE se o botão está realçado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua essa função em uma classe derivada para personalizar a aparência do botão Procurar.

##  <a name="setbrowsebuttonimage"></a>  CMFCEditBrowseCtrl::SetBrowseButtonImage

Define uma imagem personalizada no botão Procurar do controle de navegação de edição.

```
void SetBrowseButtonImage(
    HICON hIcon,
    BOOL bAutoDestroy= TRUE);


void SetBrowseButtonImage(
    HBITMAP hBitmap,
    BOOL bAutoDestroy= TRUE);

void SetBrowseButtonImage(UINT uiBmpResId);
```

### <a name="parameters"></a>Parâmetros

*hIcon*<br/>
O identificador de um ícone.

*hBitmap*<br/>
O identificador de um bitmap.

*uiBmpResId*<br/>
A ID de recurso de um bitmap.

*bAutoDestroy*<br/>
TRUE para excluir o bitmap ou ícone especificado quando esse método é encerrado; Caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use esse método para aplicar uma imagem personalizada para o botão Procurar. Por padrão, o framework obtém uma imagem padrão quando o controle de navegação de edição está em *pesquisa de arquivos* ou *Procurar pasta* modo.

##  <a name="onillegalfilename"></a>  CMFCEditBrowseCtrl::OnIllegalFileName

Chamado pelo framework quando um nome de arquivo ilegal foi inserido no controle de edição.

```
virtual BOOL OnIllegalFileName(CString& strFileName);
```

### <a name="parameters"></a>Parâmetros

*strFileName*<br/>
Especifica o nome de arquivo ilegal.

### <a name="return-value"></a>Valor de retorno

Deve retornar FALSE se esse nome de arquivo não pode ser passado para a caixa de diálogo de arquivo. Nesse caso, o foco é definido de volta para o controle de edição e o usuário deve continuar a editar. A implementação padrão exibe uma caixa de mensagem informando ao usuário sobre o nome de arquivo ilegal e retornará FALSE. Você pode substituir esse método, corrija o nome de arquivo e retornar TRUE para processamento adicional.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
