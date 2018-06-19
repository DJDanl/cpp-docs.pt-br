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
ms.openlocfilehash: 2c7214e4da0bce1a01834df556289b61e0ed8574
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33369317"
---
# <a name="cmfceditbrowsectrl-class"></a>Classe CMFCEditBrowseCtrl
O `CMFCEditBrowseCtrl` classe oferece suporte para o controle de navegação de edição, que é uma caixa de texto editável que contém, opcionalmente, um botão Procurar. Quando o usuário clica no botão, o controle executa uma ação personalizada ou exibe uma caixa de diálogo padrão que contém um navegador de arquivo ou uma pasta.  
  
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
|[CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton)|Habilita o botão Procurar e coloca o controle de navegação de edição em *Procurar arquivo* modo.|  
|[CMFCEditBrowseCtrl::EnableFolderBrowseButton](#enablefolderbrowsebutton)|Habilita o botão Procurar e coloca o controle de navegação de edição em *Procurar pasta* modo.|  
|[CMFCEditBrowseCtrl::GetMode](#getmode)|Retorna o modo de busca atual.|  
|[CMFCEditBrowseCtrl::OnAfterUpdate](#onafterupdate)|Chamado pelo framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.|  
|[CMFCEditBrowseCtrl::OnBrowse](#onbrowse)|Chamado pelo framework depois que o usuário clica no botão Procurar.|  
|[CMFCEditBrowseCtrl::OnChangeLayout](#onchangelayout)|Redesenha o controle de navegação de edição atual.|  
|[CMFCEditBrowseCtrl::OnDrawBrowseButton](#ondrawbrowsebutton)|Chamado pelo framework para desenhar o botão Procurar.|  
|[CMFCEditBrowseCtrl::OnIllegalFileName](#onillegalfilename)|Chamado pelo framework quando um nome de arquivo inválido foi inserido no controle de edição.|  
|`CMFCEditBrowseCtrl::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. Para sintaxe e obter mais informações, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).|  
|[CMFCEditBrowseCtrl::SetBrowseButtonImage](#setbrowsebuttonimage)|Define uma imagem personalizada para o botão Procurar.|  
  
## <a name="remarks"></a>Comentários  
 Use um controle de edição Procurar para selecionar um nome de arquivo ou pasta. Opcionalmente, use o controle para executar uma ação personalizada, como exibir uma caixa de diálogo. Você pode exibir ou não exibir o botão de procura, e você pode aplicar um rótulo personalizado ou uma imagem do botão.  
  
 O *modo de procura* da edição procurar controle determina se ele exibe um botão Procurar e a ação que ocorre quando o botão é clicado. Para obter mais informações, consulte o [GetMode](#getmode) método.  
  
 O `CMFCEditBrowseCtrl` classe suporta os seguintes modos.  
  
 `custom mode`  
 Uma ação personalizada é executada quando o usuário clica no botão Procurar. Por exemplo, você pode exibir uma caixa de diálogo específicas do aplicativo.  
  
 `file mode`  
 Uma caixa de diálogo de seleção de arquivo padrão é exibida quando o usuário clica no botão Procurar.  
  
 `folder mode`  
 Uma caixa de diálogo de seleção de pasta padrão é exibida quando o usuário clica no botão Procurar.  
  
## <a name="how-to-specify-an-edit-browse-control"></a>Como: Especificar um controle de navegação de edição  
 Execute as seguintes etapas para incorporar um controle de navegação de edição em seu aplicativo:  
  
1.  Se você quiser implementar um modo de navegação personalizada, derive sua própria classe do `CMFCEditBrowseCtrl` classe e, em seguida, substituir o [CMFCEditBrowseCtrl::OnBrowse](#onbrowse) método. No método substituído, executar uma ação de navegação personalizada e atualizar o controle de navegação de edição com o resultado.  
  
2.  Inserir um o `CMFCEditBrowseCtrl` objeto ou o objeto de controle Editar derivada procurar em um objeto de janela pai.  
  
3.  Se você usar o **Assistente de classe** para criar uma caixa de diálogo, adicione um controle de edição ( `CEdit`) para o formulário de caixa de diálogo. Além disso, adicione uma variável para acessar o controle em seu arquivo de cabeçalho. No seu arquivo de cabeçalho, altere o tipo da variável de `CEdit` para `CMFCEditBrowseCtrl`. O controle de navegação de edição será criado automaticamente. Se você não usar o **Assistente de classe**, adicione um `CMFCEditBrowseCtrl` variável para o arquivo de cabeçalho e em seguida, chame seu `Create` método.  
  
4.  Se você adicionar um controle de navegação de edição para uma caixa de diálogo, use o **ClassWizard** ferramenta para configurar a troca de dados.  
  
5.  Chamar o [EnableFolderBrowseButton](#enablefolderbrowsebutton), [EnableFileBrowseButton](#enablefilebrowsebutton), ou [EnableBrowseButton](#enablebrowsebutton) método para definir o modo de procura e exibir o botão Procurar. Chamar o [GetMode](#getmode) método para obter o modo de busca atual.  
  
6.  Para fornecer uma imagem personalizada para o botão Procurar, chame o [SetBrowseButtonImage](#setbrowsebuttonimage) método ou substituição de [OnDrawBrowseButton](#ondrawbrowsebutton) método.  
  
7.  Para remover o controle de navegação de edição no botão Procurar, chame o [EnableBrowseButton](#enablebrowsebutton) método com o `bEnable` parâmetro definido como `FALSE`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CEdit](../../mfc/reference/cedit-class.md)  
  
 [CMFCEditBrowseCtrl](../../mfc/reference/cmfceditbrowsectrl-class.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar dois métodos no `CMFCEditBrowseCtrl` classe: `EnableFolderBrowseButton` e `EnableFileBrowseButton`. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#6](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#7](../../mfc/reference/codesnippet/cpp/cmfceditbrowsectrl-class_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxeditbrowsectrl.h  
  
##  <a name="enablebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableBrowseButton  
 Exibe ou não exibe o botão Procurar o controle de navegação de edição atual.  
  
```  
void EnableBrowseButton(
    BOOL bEnable=TRUE,  
    LPCTSTR szLabel=_T("..."));
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 `TRUE` Para exibir o botão Procurar; `FALSE` para não exibir o botão Procurar. O valor padrão é `TRUE`.  
  
 `szLabel`  
 O rótulo que é exibido no botão Procurar. O valor padrão é " **...** ".  
  
### <a name="remarks"></a>Comentários  
 Se o `bEnable` parâmetro é `TRUE`, implementam uma ação personalizada para executar quando o botão é clicado. Para implementar uma ação personalizada, derive uma classe a partir de `CMFCEditBrowseCtrl` classe e substituir seu [OnBrowse](#onbrowse) método.  
  
 Se o `bEnable` parâmetro é `TRUE`, o modo de procura do controle é `BrowseMode_Default`; caso contrário, o modo de procura é `BrowseMode_None`. Para obter mais informações sobre modos de procura, consulte o [GetMode](#getmode) método.  
  
##  <a name="enablefilebrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFileBrowseButton  
 Exibe o botão Procurar o controle de navegação de edição atual e o coloca no *Procurar arquivo* modo.  
  
```  
void EnableFileBrowseButton(
    LPCTSTR lpszDefExt=NULL,  
    LPCTSTR lpszFilter=NULL,  
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszDefExt`  
 Especifica a extensão de nome de arquivo padrão que é usada na caixa de diálogo de seleção de arquivo. O valor padrão é `NULL`.  
  
 `lpszFilter`  
 Especifica a cadeia de caracteres de filtro padrão que é usada na caixa de diálogo de seleção de arquivo. O valor padrão é `NULL`.  
  
 `dwFlags`  
 Sinalizadores de caixa de diálogo. O valor padrão é uma combinação bit a bit (ou) de OFN_HIDEREADONLY e OFN_OVERWRITEPROMPT.  
  
### <a name="remarks"></a>Comentários  
 Quando o controle de navegação de edição está no modo de procura de arquivo e o usuário clica no botão, o controle exibe a caixa de diálogo de seleção de arquivo padrão.  
  
 Para obter uma lista completa de sinalizadores disponíveis, consulte [estrutura OPENFILENAME](https://msdn.microsoft.com/library/ms646839.aspx).  
  
##  <a name="enablefolderbrowsebutton"></a>  CMFCEditBrowseCtrl::EnableFolderBrowseButton  
 Exibe o botão Procurar o controle de navegação de edição atual e o coloca no *Procurar pasta* modo.  
  
```  
void EnableFolderBrowseButton();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o controle de navegação de edição está no modo de procura da pasta e o usuário clica no botão, o controle exibe a caixa de diálogo de seleção de pasta padrão.  
  
##  <a name="getmode"></a>  CMFCEditBrowseCtrl::GetMode  
 Recupera o modo de busca do controle de navegação de edição atual.  
  
```  
CMFCEditBrowseCtrl::BrowseMode GetMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores de enumeração que especifica o modo atual da edição navegar no controle. O modo de busca determina se a estrutura exibe o botão Procurar e a ação que ocorre quando um usuário clicar nesse botão.  
  
 A tabela a seguir lista os possíveis valores de retorno.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`BrowseMode_Default`|`custom mode`. Uma ação definida pelo programador é executada.|  
|`BrowseMode_File`|`file mode`. A caixa de diálogo de navegador de arquivo padrão é exibida.|  
|`BrowseMode_Folder`|`folder mode`. A caixa de diálogo de navegador de pasta padrão é exibida.|  
|`BrowseMode_None`|Não é exibido no botão Procurar.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, um `CMFCEditBrowseCtrl` objeto é inicializado para `BrowseMode_None` modo. Modificar o modo de busca com o [CMFCEditBrowseCtrl::EnableBrowseButton](#enablebrowsebutton), [CMFCEditBrowseCtrl::EnableFileBrowseButton](#enablefilebrowsebutton), e [CMFCEditBrowseCtrl::EnableFolderBrowseButton ](#enablefolderbrowsebutton) métodos.  
  
##  <a name="onafterupdate"></a>  CMFCEditBrowseCtrl::OnAfterUpdate  
 Chamado pelo framework depois que o controle de navegação de edição é atualizado com o resultado de uma ação de navegação.  
  
```  
virtual void OnAfterUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada para implementar uma ação personalizada.  
  
##  <a name="onbrowse"></a>  CMFCEditBrowseCtrl::OnBrowse  
 Chamado pelo framework depois que o usuário clica no botão de procura do controle de edição.  
  
```  
virtual void OnBrowse();
```  
  
### <a name="remarks"></a>Comentários  
 Use esse método para executar código personalizado quando o usuário clica no botão de procura do controle de edição. Derive sua própria classe do `CMFCEditBrowseCtrl` classe e substituir seu `OnBrowse` método. Nesse método, implementam uma ação de navegação personalizada e, opcionalmente, atualize a caixa de texto do controle de navegação de edição. Em seu aplicativo, use o [EnableBrowseButton](#enablebrowsebutton) método para colocar o controle de navegação de edição em *navegação personalizada* modo.  
  
##  <a name="onchangelayout"></a>  CMFCEditBrowseCtrl::OnChangeLayout  
 Redesenha o controle de navegação de edição atual.  
  
```  
virtual void OnChangeLayout();
```  
  
### <a name="remarks"></a>Comentários  
 O framework chama este método quando o modo de procura da edição procurar controlar alterações. Para obter mais informações, consulte [CMFCEditBrowseCtrl::GetMode](#getmode).  
  
##  <a name="ondrawbrowsebutton"></a>  CMFCEditBrowseCtrl::OnDrawBrowseButton  
 Chamado pelo framework para desenhar o controle de navegação de edição no botão Procurar.  
  
```  
virtual void OnDrawBrowseButton(
    CDC* pDC,  
    CRect rect,  
    BOOL bIsButtonPressed,  
    BOOL bIsButtonHot);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 `Rect`  
 O retângulo delimitador do botão Procurar.  
  
 `bIsButtonPressed`  
 `TRUE` Se o botão for pressionado; Caso contrário, `FALSE`.  
  
 `bIsButtonHot`  
 `TRUE` Se o botão é realçado; Caso contrário, `FALSE`.  
  
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
 `hIcon`  
 O identificador de um ícone.  
  
 `hBitmap`  
 O identificador de um bitmap.  
  
 `uiBmpResId`  
 A ID de recurso de um bitmap.  
  
 `bAutoDestroy`  
 `TRUE` Para excluir o bitmap ou ícone especificado quando este método será encerrado; Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para aplicar uma imagem personalizada para o botão Procurar. Por padrão, o framework obtém uma imagem padrão quando o controle de navegação de edição está em *Procurar arquivo* ou *Procurar pasta* modo.  
  
##  <a name="onillegalfilename"></a>  CMFCEditBrowseCtrl::OnIllegalFileName  
 Chamado pelo framework quando um nome de arquivo inválido foi inserido no controle de edição.  
  
```  
virtual BOOL OnIllegalFileName(CString& strFileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strFileName`  
 Especifica o nome de arquivo ilegal.  
  
### <a name="return-value"></a>Valor de retorno  
 Deve retornar `FALSE` se este nome de arquivo não pode ser passado para a caixa de diálogo de arquivo. Nesse caso, o foco é redefinido para o controle de edição e o usuário deve continuar editando. A implementação padrão exibe uma caixa de mensagem informando ao usuário sobre o nome de arquivo ilegal e retorna `FALSE`. Substitua este método, corrija o nome de arquivo e retornar `TRUE` para processamento adicional.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
