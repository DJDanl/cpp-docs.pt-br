---
title: Classe CComboBoxEx | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComboBoxEx
- AFXCMN/CComboBoxEx
- AFXCMN/CComboBoxEx::CComboBoxEx
- AFXCMN/CComboBoxEx::Create
- AFXCMN/CComboBoxEx::CreateEx
- AFXCMN/CComboBoxEx::DeleteItem
- AFXCMN/CComboBoxEx::GetComboBoxCtrl
- AFXCMN/CComboBoxEx::GetEditCtrl
- AFXCMN/CComboBoxEx::GetExtendedStyle
- AFXCMN/CComboBoxEx::GetImageList
- AFXCMN/CComboBoxEx::GetItem
- AFXCMN/CComboBoxEx::HasEditChanged
- AFXCMN/CComboBoxEx::InsertItem
- AFXCMN/CComboBoxEx::SetExtendedStyle
- AFXCMN/CComboBoxEx::SetImageList
- AFXCMN/CComboBoxEx::SetItem
- AFXCMN/CComboBoxEx::SetWindowTheme
dev_langs:
- C++
helpviewer_keywords:
- extended combo boxes, CComboBoxEx class
- Windows common controls [C++], extended combo boxes
- common controls [C++], extended combo boxes
- combo boxes [C++], CComboBoxEx class
- Internet Explorer 4.0 common controls
- CComboBoxEx class
ms.assetid: 33ca960a-2409-478c-84a4-a2ee8ecfe8f7
caps.latest.revision: 26
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
ms.openlocfilehash: e88ed701111b49e3a5d3b32868bfad8e77206086
ms.lasthandoff: 02/25/2017

---
# <a name="ccomboboxex-class"></a>Classe CComboBoxEx
Estende a combinação controle caixa fornecendo suporte para listas de imagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CComboBoxEx : public CComboBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBoxEx::CComboBoxEx](#ccomboboxex)|Constrói um objeto `CComboBoxEx`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBoxEx::Create](#create)|Cria a caixa de combinação e anexa-o para o `CComboBoxEx` objeto.|  
|[CComboBoxEx::CreateEx](#createex)|Cria uma caixa de combinação com os estilos estendidos do Windows especificados e a anexa a um **ComboBoxEx** objeto.|  
|[CComboBoxEx::DeleteItem](#deleteitem)|Remove um item de um **ComboBoxEx** controle.|  
|[CComboBoxEx::GetComboBoxCtrl](#getcomboboxctrl)|Recupera um ponteiro para o controle filho de caixa de combinação.|  
|[CComboBoxEx::GetEditCtrl](#geteditctrl)|Recupera o identificador para a parte do controle de edição de um **ComboBoxEx** controle.|  
|[CComboBoxEx::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que estão em uso para um **ComboBoxEx** controle.|  
|[CComboBoxEx::GetImageList](#getimagelist)|Recupera um ponteiro para a lista de imagens atribuído a um **ComboBoxEx** controle.|  
|[CComboBoxEx::GetItem](#getitem)|Item de recupera informações para um determinado **ComboBoxEx** item.|  
|[CComboBoxEx::HasEditChanged](#haseditchanged)|Determina se o usuário tiver alterado o conteúdo a **ComboBoxEx** controle de edição digitando.|  
|[CComboBoxEx::InsertItem](#insertitem)|Insere um novo item em uma **ComboBoxEx** controle.|  
|[CComboBoxEx::SetExtendedStyle](#setextendedstyle)|Define estilos estendidos em um **ComboBoxEx** controle.|  
|[CComboBoxEx::SetImageList](#setimagelist)|Define uma lista de imagens para uma **ComboBoxEx** controle.|  
|[CComboBoxEx::SetItem](#setitem)|Define os atributos de um item em uma **ComboBoxEx** controle.|  
|[CComboBoxEx::SetWindowTheme](#setwindowtheme)|Define o estilo visual da caixa de combinação estendida controle de caixa.|  
  
## <a name="remarks"></a>Comentários  
 Usando `CComboBoxEx` para criar controles de caixa de combinação, você não precisa implementar seu próprio código de desenho de imagem. Em vez disso, use `CComboBoxEx` para imagens de acesso de uma lista de imagens.  
  
## <a name="image-list-support"></a>Suporte à lista de imagem  
 Em uma caixa de combinação padrão, o proprietário da caixa de combinação é responsável por desenhar uma imagem ao criar a caixa de combinação, como um controle de desenho proprietário. Quando você usa `CComboBoxEx`, você não precisa definir os estilos de desenho **CBS_OWNERDRAWFIXED** e **CBS_HASSTRINGS** porque eles estão implícitas. Caso contrário, você deve escrever código para executar operações de desenho. Um `CComboBoxEx` controle oferece suporte a até três imagens por item: um para um estado selecionado, um para um estado desmarcado e outro para uma imagem de sobreposição.  
  
## <a name="styles"></a>Estilos  
 `CComboBoxEx`suporte os estilos **CBS_SIMPLE**, **CBS_DROPDOWN**, **CBS_DROPDOWNLIST**, e **WS_CHILD**. Todos os outros estilos passados ao criar a janela são ignorados pelo controle. Depois que a janela é criada, você pode fornecer outra combinação estilos de caixa chamando o `CComboBoxEx` função de membro [SetExtendedStyle](#setextendedstyle). Com esses estilos, você pode:  
  
-   Pesquisa de cadeia de caracteres do conjunto na lista para diferenciar maiusculas de minúsculas.  
  
-   Criar um controle caixa de combinação que usa a barra ('/'), barra invertida ('\\') e o período ('. ') caracteres como delimitadores de palavras. Isso permite aos usuários saltar do word para word, usando o atalho de teclado CTRL + seta.  
  
-   Defina a caixa de combinação controle de caixa para exibir ou não exibir uma imagem. Se nenhuma imagem for exibida, a caixa de combinação pode remover o recuo de texto que acomoda uma imagem.  
  
-   Crie um controle de caixa de combinação específica, incluindo redimensioná-la para que ele cortará a maior caixa de combinação contém.  
  
 Esses sinalizadores de estilo são descritos mais detalhadamente em [CComboBoxEx usando](../../mfc/using-ccomboboxex.md).  
  
## <a name="item-retention-and-callback-item-attributes"></a>Retenção de itens e atributos do Item de retorno de chamada  
 Informações de item, como índices para itens e imagens, os valores de recuo e cadeias de caracteres de texto, são armazenadas na estrutura do Win32 [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. A estrutura também contém membros que correspondem aos sinalizadores de retorno de chamada.  
  
 Para obter uma discussão detalhada, conceitual, consulte [CComboBoxEx usando](../../mfc/using-ccomboboxex.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CComboBox](../../mfc/reference/ccombobox-class.md)  
  
 `CComboBoxEx`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="ccomboboxex"></a>CComboBoxEx::CComboBoxEx  
 Chame essa função de membro para criar um `CComboBoxEx` objeto.  
  
```  
CComboBoxEx();
```  
  
##  <a name="create"></a>CComboBoxEx::Create  
 Cria a caixa de combinação e anexa-o para o `CComboBoxEx` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica a combinação de estilos de caixa de combinação aplicada à caixa de combinação. Consulte **comentários** abaixo para obter mais informações sobre estilos.  
  
 `rect`  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e o tamanho da caixa de combinação.  
  
 `pParentWnd`  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de combinação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Criar um `CComboBoxEx` objeto em duas etapas:  
  
1.  Chamar [CComboBoxEx](#ccomboboxex) para construir uma `CComboBoxEx` objeto.  
  
2.  Chame essa função de membro, que cria a caixa de combinação estendida do Windows e anexa-o para o `CComboBoxEx` objeto.  
  
 Quando você chama **criar**, MFC inicializa os controles comuns.  
  
 Quando você cria a caixa de combinação, você pode especificar qualquer ou todos os seguintes estilos de caixa de combinação:  
  
- **CBS_SIMPLE**  
  
- **CBS_DROPDOWN**  
  
- **CBS_DROPDOWNLIST**  
  
- **CBS_AUTOHSCROLL**  
  
- **ESTILO**  
  
 Todos os outros estilos passados ao criar a janela são ignorados. O **ComboBoxEx** controle também oferece suporte a estilos estendidos que fornecem recursos adicionais. Esses estilos são descritos em [ComboBoxEx controlar estilos estendidos](http://msdn.microsoft.com/library/windows/desktop/bb775742), no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Definir esses estilos chamando [SetExtendedStyle](#setextendedstyle).  
  
 Se você quiser usar estilos estendidos do windows com o controle, chame [CreateEx](#createex) em vez de **criar**.  
  
##  <a name="createex"></a>CComboBoxEx::CreateEx  
 Chame essa função para criar um controle de caixa de combinação estendido (uma janela filho) e associá-lo a `CComboBoxEx` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Estilo do controle de caixa de combinação. Consulte [criar](#create) para obter uma lista de estilos.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de **criar** para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
 `CreateEx`cria o controle com os estilos estendidos do Windows especificados pela `dwExStyle`. Você deve definir estilos estendidos específicos para um controle de caixa de combinação estendidas usando [SetExtendedStyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como **WS_EX_CONTEXTHELP**, mas usar `SetExtendedStyle` para definir esses estilos como **CBES_EX_CASESENSITIVE**. Para obter mais informações, consulte os estilos descritos no tópico [estilos estendidos de controle ComboBoxEx](http://msdn.microsoft.com/library/windows/desktop/bb775742) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="deleteitem"></a>CComboBoxEx::DeleteItem  
 Remove um item de um **ComboBoxEx** controle.  
  
```  
int DeleteItem(int iIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iIndex`  
 Índice baseado em zero do item a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens restantes no controle. Se `iIndex` for inválido, a função retornará **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a funcionalidade da mensagem [CBEM_DELETEITEM](http://msdn.microsoft.com/library/windows/desktop/bb775768), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Quando você chama DeleteItem, uma [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem **CBEN_DELETEITEM** notificação será enviada para a janela pai.  
  
##  <a name="getcomboboxctrl"></a>CComboBoxEx::GetComboBoxCtrl  
 Chame essa função de membro para obter um ponteiro para um controle de caixa de combinação em um `CComboBoxEx` objeto.  
  
```  
CComboBox* GetComboBoxCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CComboBox` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CComboBoxEx` controle consiste em uma janela pai, que encapsula um `CComboBox`.  
  
 O `CComboBox` objeto apontado pelo valor de retorno é um objeto temporário e destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="geteditctrl"></a>CComboBoxEx::GetEditCtrl  
 Chame essa função de membro para obter um ponteiro para o controle de edição para uma caixa de combinação.  
  
```  
CEdit* GetEditCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CEdit](../../mfc/reference/cedit-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 A `CComboBoxEx` controle usa uma caixa de edição quando ele é criado com o **CBS_DROPDOWN** estilo.  
  
 O `CEdit` objeto apontado pelo valor de retorno é um objeto temporário e destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="getextendedstyle"></a>CComboBoxEx::GetExtendedStyle  
 Chame essa função de membro para obter os estilos estendidos usados para um `CComboBoxEx` controle.  
  
```  
DWORD GetExtendedStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `DWORD` valor que contém os estilos estendidos que são usados para o controle de caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Consulte [estilos estendidos de controle ComboBoxEx](http://msdn.microsoft.com/library/windows/desktop/bb775742) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre esses estilos.  
  
##  <a name="getimagelist"></a>CComboBoxEx::GetImageList  
 Chame essa função de membro para obter um ponteiro para a lista de imagens usada por um `CComboBoxEx` controle.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto. Se ele falha, essa função membro retorna **nulo**.  
  
### <a name="remarks"></a>Comentários  
 O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="getitem"></a>CComboBoxEx::GetItem  
 Item de recupera informações para um determinado **ComboBoxEx** item.  
  
```  
BOOL GetItem(COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCBItem`  
 Um ponteiro para um [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746) estrutura que receberá as informações do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a funcionalidade da mensagem [CBEM_GETITEM](http://msdn.microsoft.com/library/windows/desktop/bb775779), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="haseditchanged"></a>CComboBoxEx::HasEditChanged  
 Determina se o usuário tiver alterado o conteúdo a **ComboBoxEx** controle de edição digitando.  
  
```  
BOOL HasEditChanged();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário tiver digitado na caixa de edição do controle; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a funcionalidade da mensagem [CBEM_HASEDITCHANGED](http://msdn.microsoft.com/library/windows/desktop/bb775782), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="insertitem"></a>CComboBoxEx::InsertItem  
 Insere um novo item em uma **ComboBoxEx** controle.  
  
```  
int InsertItem(const COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCBItem`  
 Um ponteiro para um [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746) estrutura que receberá as informações do item. Essa estrutura contém valores de sinalizador de retorno de chamada para o item.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice no qual o novo item foi inserido se for bem-sucedida; Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
 Quando você chama `InsertItem`, um [WM_NOTIFY](http://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem [CBEN_INSERTITEM](http://msdn.microsoft.com/library/windows/desktop/bb775764) notificação será enviada para a janela pai.  
  
##  <a name="setextendedstyle"></a>CComboBoxEx::SetExtendedStyle  
 Chame essa função de membro para definir os estilos estendidos usados para uma caixa de combinação estendido de controle.  
  
```  
DWORD SetExtendedStyle(
    DWORD dwExMask,  
    DWORD dwExStyles);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExMask`  
 A `DWORD` valor que indica quais estilos no `dwExStyles` são afetados. Somente os estilos estendidos em `dwExMask` será alterado. Todos os outros estilos serão mantidos como está. Se esse parâmetro for zero, então todos os estilos no `dwExStyles` serão afetados.  
  
 `dwExStyles`  
 Um `DWORD` estilos estendidos devem ser definidas para o controle de controle de valor que contém a caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que contém os estilos estendidos usados anteriormente para o controle.  
  
### <a name="remarks"></a>Comentários  
 Consulte [estilos estendidos de controle ComboBoxEx](http://msdn.microsoft.com/library/windows/desktop/bb775742) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações sobre esses estilos.  
  
 Para criar uma caixa de combinação estendido controle com estilos estendidos do windows, use [CreateEx](#createex).  
  
##  <a name="setimagelist"></a>CComboBoxEx::SetImageList  
 Define uma lista de imagens para uma **ComboBoxEx** controle.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um `CImageList` objeto que contém as imagens a serem usadas com o `CComboBoxEx` controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que contém as imagens usadas anteriormente pelo `CComboBoxEx` controle. **NULO** se nenhuma lista de imagens foi definida anteriormente.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a funcionalidade da mensagem [CBEM_SETIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb775787), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Se você alterar a altura do controle de edição padrão, chame a função Win32 [SetWindowPos](http://msdn.microsoft.com/library/windows/desktop/ms633545) para redimensionar o controle depois de você chamar `SetImageList`, ou ele não será exibido corretamente.  
  
 O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="setitem"></a>CComboBoxEx::SetItem  
 Define os atributos de um item em uma **ComboBoxEx** controle.  
  
```  
BOOL SetItem(const COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCBItem`  
 Um ponteiro para um [COMBOBOXEXITEM](http://msdn.microsoft.com/library/windows/desktop/bb775746) estrutura que receberá as informações do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a funcionalidade da mensagem [CBEM_SETITEM](http://msdn.microsoft.com/library/windows/desktop/bb775788), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setwindowtheme"></a>CComboBoxEx::SetWindowTheme  
 Define o estilo visual da caixa de combinação estendida controle de caixa.  
  
```  
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszSubAppName`  
 Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual de caixa de combinação estendido para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno não é usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [CBEM_SETWINDOWTHEME](http://msdn.microsoft.com/library/windows/desktop/bb775790) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)

