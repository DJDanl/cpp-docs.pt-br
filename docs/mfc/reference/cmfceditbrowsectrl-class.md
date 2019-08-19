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
ms.openlocfilehash: db99c5e72e84bb359184f4c62594fcddff7d8ff6
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505349"
---
# <a name="cmfceditbrowsectrl-class"></a>Classe CMFCEditBrowseCtrl

A `CMFCEditBrowseCtrl` classe dá suporte ao controle de navegação de edição, que é uma caixa de texto editável que, opcionalmente, contém um botão procurar. Quando o usuário clica no botão procurar, o controle executa uma ação personalizada ou exibe uma caixa de diálogo padrão que contém um navegador de arquivos ou um navegador de pastas.

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
|[CMFCEditBrowseCtrl::EnableBrowseButton](#enablebrowsebutton)|Habilita ou desabilita (oculta) o botão procurar.|
|[CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton)|Habilita o botão procurar e coloca o controle de navegação de edição no modo de *procura de arquivo* .|
|[CMFCEditBrowseCtrl::EnableFolderBrowseButton](#enablefolderbrowsebutton)|Habilita o botão procurar e coloca o controle de navegação de edição no modo de *procura de pasta* .|
|[CMFCEditBrowseCtrl::GetMode](#getmode)|Retorna o modo de procura atual.|
|[CMFCEditBrowseCtrl::OnAfterUpdate](#onafterupdate)|Chamado pelo Framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de procura.|
|[CMFCEditBrowseCtrl::OnBrowse](#onbrowse)|Chamado pelo Framework depois que o usuário clica no botão procurar.|
|[CMFCEditBrowseCtrl::OnChangeLayout](#onchangelayout)|Redesenha o controle de navegação de edição atual.|
|[CMFCEditBrowseCtrl::OnDrawBrowseButton](#ondrawbrowsebutton)|Chamado pelo Framework para desenhar o botão procurar.|
|[CMFCEditBrowseCtrl::OnIllegalFileName](#onillegalfilename)|Chamado pelo Framework quando um nome de arquivo ilegal foi inserido no controle de edição.|
|`CMFCEditBrowseCtrl::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . Para obter a sintaxe e obter mais informações, consulte [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).|
|[CMFCEditBrowseCtrl::SetBrowseButtonImage](#setbrowsebuttonimage)|Define uma imagem personalizada para o botão procurar.|

## <a name="remarks"></a>Comentários

Use um controle de navegação de edição para selecionar um nome de arquivo ou pasta. Opcionalmente, use o controle para executar uma ação personalizada, como para exibir uma caixa de diálogo. Você pode exibir ou não exibir o botão procurar, e pode aplicar um rótulo ou uma imagem personalizada no botão.

O *modo de procura* do controle de navegação de edição determina se ele exibe um botão de procura e qual ação ocorre quando o botão é clicado. Para obter mais informações, consulte o método [GetMode](#getmode).

A `CMFCEditBrowseCtrl` classe oferece suporte aos seguintes modos.

- **modo personalizado**

   Uma ação personalizada é executada quando o usuário clica no botão procurar. Por exemplo, você pode exibir uma caixa de diálogo específica do aplicativo.

- **modo de arquivo**

   Uma caixa de diálogo seleção de arquivo padrão é exibida quando o usuário clica no botão procurar.

- **modo de pasta**

   Uma caixa de diálogo seleção de pasta padrão é exibida quando o usuário clica no botão procurar.

## <a name="how-to-specify-an-edit-browse-control"></a>Como fazer: Especificar um controle de navegação de edição

Execute as seguintes etapas para incorporar um controle de navegação de edição em seu aplicativo:

1. Se você quiser implementar um modo de procura personalizado, derive sua própria classe da `CMFCEditBrowseCtrl` classe e, em seguida, substitua o método [CMFCEditBrowseCtrl:: onprocurar](#onbrowse) . No método substituído, execute uma ação de navegação personalizada e atualize o controle de navegação de edição com o resultado.

1. Insira o `CMFCEditBrowseCtrl` objeto ou o objeto de controle de navegação de edição derivada no objeto de janela pai.

1. Se você usar o **Assistente de classe** para criar uma caixa de diálogo, adicione um controle `CEdit`de edição () ao formulário da caixa de diálogo. Além disso, adicione uma variável para acessar o controle no arquivo de cabeçalho. No arquivo de cabeçalho, altere o tipo da variável de `CEdit` para. `CMFCEditBrowseCtrl` O controle de navegação de edição será criado automaticamente. Se você não usar o **Assistente de classe**, adicione uma `CMFCEditBrowseCtrl` variável ao arquivo de cabeçalho e, em seguida `Create` , chame seu método.

1. Se você adicionar um controle de navegação de edição a uma caixa de diálogo, use a ferramenta **ClassWizard** para configurar a troca de dados.

1. Chame o método [EnableFolderBrowseButton](#enablefolderbrowsebutton), [EnableFileBrowseButton](#enablefilebrowsebutton)ou [EnableBrowseButton](#enablebrowsebutton) para definir o modo de procura e exibir o botão procurar. Chame o método [GetMode](#getmode) para obter o modo de procura atual.

1. Para fornecer uma imagem personalizada para o botão procurar, chame o método [SetBrowseButtonImage](#setbrowsebuttonimage) ou substitua o método [OnDrawBrowseButton](#ondrawbrowsebutton) .

1. Para remover o botão procurar do controle de navegação de edição, chame o método [EnableBrowseButton](#enablebrowsebutton) com o parâmetro *BENABLE* definido como false.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CEdit](../../mfc/reference/cedit-class.md)

[CMFCEditBrowseCtrl](../../mfc/reference/cmfceditbrowsectrl-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar dois métodos na `CMFCEditBrowseCtrl` classe: `EnableFolderBrowseButton` e `EnableFileBrowseButton`. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#6](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#7](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxeditbrowsectrl. h

##  <a name="enablebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableBrowseButton

Exibe ou não exibe o botão procurar no controle atual de navegação de edição.

```
void EnableBrowseButton(
    BOOL bEnable=TRUE,
    LPCTSTR szLabel=_T("..."));
```

### <a name="parameters"></a>Parâmetros

*bEnable*<br/>
TRUE para exibir o botão procurar; FALSE não exibir o botão procurar. O valor padrão é TRUE.

*szLabel*<br/>
O rótulo que é exibido no botão procurar. O valor padrão é " **...** ".

### <a name="remarks"></a>Comentários

Se o parâmetro *bEnable* for true, implemente uma ação personalizada a ser executada quando o botão procurar for clicado. Para implementar uma ação personalizada, derive uma classe da `CMFCEditBrowseCtrl` classe e, em seguida, substitua seu método [OnBrowse](#onbrowse).

Se o parâmetro *bEnable* for true, o modo de procura do controle será `BrowseMode_Default`; caso contrário, o modo de `BrowseMode_None`procura será. Para obter mais informações sobre os modos de procura, consulte o método [GetMode](#getmode).

##  <a name="enablefilebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFileBrowseButton

Exibe o botão procurar no controle de navegação de edição atual e coloca o controle no modo de *procura de arquivo* .

```
void EnableFileBrowseButton(
    LPCTSTR lpszDefExt=NULL,
    LPCTSTR lpszFilter=NULL,
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT);
```

### <a name="parameters"></a>Parâmetros

*lpszDefExt*<br/>
Especifica a extensão de nome de arquivo padrão usada na caixa de diálogo seleção de arquivo. O valor padrão é NULL.

*lpszFilter*<br/>
Especifica a cadeia de caracteres de filtro padrão usada na caixa de diálogo de seleção de arquivo. O valor padrão é NULL.

*dwFlags*<br/>
Sinalizadores da caixa de diálogo. O valor padrão é uma combinação de bits (ou) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição está no modo de procura de arquivo e o usuário clica no botão procurar, o controle exibe a caixa de diálogo seleção de arquivo padrão.

Para obter uma lista completa dos sinalizadores disponíveis, consulte [estrutura da OPENFILENAME](/windows/win32/api/commdlg/ns-commdlg-openfilenamew).

##  <a name="enablefolderbrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFolderBrowseButton

Exibe o botão procurar no controle de navegação de edição atual e coloca o controle no modo de *procura de pasta* .

```
void EnableFolderBrowseButton();
```

### <a name="remarks"></a>Comentários

Quando o controle de navegação de edição está no modo de procura de pasta e o usuário clica no botão procurar, o controle exibe a caixa de diálogo seleção de pasta padrão.

##  <a name="getmode"></a>  CMFCEditBrowseCtrl::GetMode

Recupera o modo de procura do controle de navegação de edição atual.

```
CMFCEditBrowseCtrl::BrowseMode GetMode() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos valores de enumeração que especifica o modo atual do controle de navegação de edição. O modo de procura determina se a estrutura exibe o botão procurar e que ação ocorre quando um usuário clica nesse botão.

A tabela a seguir lista os possíveis valores de retorno.

|Valor|Descrição|
|-----------|-----------------|
|`BrowseMode_Default`|**modo personalizado**. Uma ação definida pelo programador é executada.|
|`BrowseMode_File`|**modo de arquivo**. A caixa de diálogo navegador de arquivos padrão é exibida.|
|`BrowseMode_Folder`|**modo de pasta**. A caixa de diálogo navegador de pastas padrão é exibida.|
|`BrowseMode_None`|O botão procurar não é exibido.|

### <a name="remarks"></a>Comentários

Por padrão, um `CMFCEditBrowseCtrl` objeto é inicializado `BrowseMode_None` para o modo. Modifique o modo de procura com os métodos [CMFCEditBrowseCtrl:: EnableBrowseButton](#enablebrowsebutton), [CMFCEditBrowseCtrl:: EnableFileBrowseButton](#enablefilebrowsebutton)e [CMFCEditBrowseCtrl:: EnableFolderBrowseButton](#enablefolderbrowsebutton) .

##  <a name="onafterupdate"></a>  CMFCEditBrowseCtrl::OnAfterUpdate

Chamado pelo Framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de procura.

```
virtual void OnAfterUpdate();
```

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar uma ação personalizada.

##  <a name="onbrowse"></a>  CMFCEditBrowseCtrl::OnBrowse

Chamado pelo Framework depois que o usuário clica no botão procurar do controle de navegação de edição.

```
virtual void OnBrowse();
```

### <a name="remarks"></a>Comentários

Use esse método para executar código personalizado quando o usuário clicar no botão procurar do controle de navegação de edição. Derive sua própria classe da `CMFCEditBrowseCtrl` classe e substitua seu `OnBrowse` método. Nesse método, implemente uma ação de navegação personalizada e, opcionalmente, atualize a caixa de texto do controle de navegação de edição. Em seu aplicativo, use o método [EnableBrowseButton](#enablebrowsebutton) para colocar o controle de navegação de edição no modo de *procura personalizado* .

##  <a name="onchangelayout"></a>  CMFCEditBrowseCtrl::OnChangeLayout

Redesenha o controle de navegação de edição atual.

```
virtual void OnChangeLayout();
```

### <a name="remarks"></a>Comentários

A estrutura chama esse método quando o modo de procura do controle de navegação de edição é alterado. Para obter mais informações, consulte [CMFCEditBrowseCtrl:: GetMode](#getmode).

##  <a name="ondrawbrowsebutton"></a>  CMFCEditBrowseCtrl::OnDrawBrowseButton

Chamado pelo Framework para desenhar o botão procurar no controle de navegação de edição.

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

*Retângulo*<br/>
O retângulo delimitador do botão procurar.

*bIsButtonPressed*<br/>
TRUE se o botão for pressionado; caso contrário, FALSE.

*bIsButtonHot*<br/>
TRUE se o botão estiver realçado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua essa função em uma classe derivada para personalizar a aparência do botão procurar.

##  <a name="setbrowsebuttonimage"></a>  CMFCEditBrowseCtrl::SetBrowseButtonImage

Define uma imagem personalizada no botão procurar do controle de navegação de edição.

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
TRUE para excluir o ícone ou bitmap especificado quando esse método for encerrado; caso contrário, FALSE. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Use este método para aplicar uma imagem personalizada ao botão procurar. Por padrão, a estrutura Obtém uma imagem padrão quando o controle de navegação de edição está no modo de procura de *arquivo* ou de *pasta* .

##  <a name="onillegalfilename"></a>  CMFCEditBrowseCtrl::OnIllegalFileName

Chamado pelo Framework quando um nome de arquivo ilegal foi inserido no controle de edição.

```
virtual BOOL OnIllegalFileName(CString& strFileName);
```

### <a name="parameters"></a>Parâmetros

*strFileName*<br/>
Especifica o nome de arquivo ilegal.

### <a name="return-value"></a>Valor de retorno

Deve retornar FALSE se esse nome de arquivo não puder ser passado para a caixa de diálogo de arquivo. Nesse caso, o foco é definido de volta para o controle de edição e o usuário deve continuar editando. A implementação padrão exibe uma caixa de mensagem informando ao usuário sobre o nome de arquivo ilegal e retorna FALSE. Você pode substituir esse método, corrigir o nome do arquivo e retornar TRUE para processamento adicional.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
