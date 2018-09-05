---
title: Classe CComboBoxEx | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CComboBoxEx [MFC], CComboBoxEx
- CComboBoxEx [MFC], Create
- CComboBoxEx [MFC], CreateEx
- CComboBoxEx [MFC], DeleteItem
- CComboBoxEx [MFC], GetComboBoxCtrl
- CComboBoxEx [MFC], GetEditCtrl
- CComboBoxEx [MFC], GetExtendedStyle
- CComboBoxEx [MFC], GetImageList
- CComboBoxEx [MFC], GetItem
- CComboBoxEx [MFC], HasEditChanged
- CComboBoxEx [MFC], InsertItem
- CComboBoxEx [MFC], SetExtendedStyle
- CComboBoxEx [MFC], SetImageList
- CComboBoxEx [MFC], SetItem
- CComboBoxEx [MFC], SetWindowTheme
ms.assetid: 33ca960a-2409-478c-84a4-a2ee8ecfe8f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd480e7b1ffb0923e33361c545bca68202ec3f4f
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43687710"
---
# <a name="ccomboboxex-class"></a>Classe CComboBoxEx
Estende a caixa de combinação controle de caixa, fornecendo suporte para listas de imagens.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CComboBoxEx : public CComboBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBoxEx::CComboBoxEx](#ccomboboxex)|Constrói um objeto `CComboBoxEx`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBoxEx::Create](#create)|Cria a caixa de combinação e anexa-o para o `CComboBoxEx` objeto.|  
|[CComboBoxEx::CreateEx](#createex)|Cria uma caixa de combinação com os estilos estendidos do Windows especificados e anexa-o para um `ComboBoxEx` objeto.|  
|[CComboBoxEx::DeleteItem](#deleteitem)|Remove um item de um `ComboBoxEx` controle.|  
|[CComboBoxEx::GetComboBoxCtrl](#getcomboboxctrl)|Recupera um ponteiro para o controle de caixa de combinação de filho.|  
|[CComboBoxEx::GetEditCtrl](#geteditctrl)|Recupera o identificador para a parte do controle de edição de um `ComboBoxEx` controle.|  
|[CComboBoxEx::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que estão em uso para um `ComboBoxEx` controle.|  
|[CComboBoxEx::GetImageList](#getimagelist)|Recupera um ponteiro para a lista de imagens atribuído a um `ComboBoxEx` controle.|  
|[CComboBoxEx::GetItem](#getitem)|Item de recupera informações para um determinado `ComboBoxEx` item.|  
|[CComboBoxEx::HasEditChanged](#haseditchanged)|Determina se o usuário alterou o conteúdo do `ComboBoxEx` Editar controle digitando.|  
|[CComboBoxEx::InsertItem](#insertitem)|Insere um novo item em uma `ComboBoxEx` controle.|  
|[CComboBoxEx::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos dentro de um `ComboBoxEx` controle.|  
|[CComboBoxEx::SetImageList](#setimagelist)|Define uma lista de imagens para um `ComboBoxEx` controle.|  
|[CComboBoxEx::SetItem](#setitem)|Define os atributos de um item em um `ComboBoxEx` controle.|  
|[CComboBoxEx::SetWindowTheme](#setwindowtheme)|Define o estilo visual da caixa de combinação estendida, de controle de caixa.|  
  
## <a name="remarks"></a>Comentários  
 Usando `CComboBoxEx` para criar controles de caixa de combinação, você não precisa implementar seu próprio código de desenho da imagem. Em vez disso, use `CComboBoxEx` para imagens de acesso de uma lista de imagens.  
  
## <a name="image-list-support"></a>Suporte à lista de imagem  
 Em uma caixa de combinação padrão, o proprietário da caixa de combinação é responsável por desenhar uma imagem ao criar a caixa de combinação como um controle de desenho proprietário. Quando você usa `CComboBoxEx`, você não precisa definir os estilos de desenho CBS_OWNERDRAWFIXED e CBS_HASSTRINGS, porque eles são deduzidos. Caso contrário, você deve escrever código para executar operações de desenho. Um `CComboBoxEx` controle dá suporte a até três imagens por item: um para um estado selecionado, um para um estado não selecionado e um para uma imagem de sobreposição.  
  
## <a name="styles"></a>Estilos  
 `CComboBoxEx` dá suporte a estilos WS_CHILD, CBS_DROPDOWN, CBS_DROPDOWNLIST e CBS_SIMPLE. Todos os outros estilos passados ao criar a janela são ignorados pelo controle. Depois que a janela é criada, você pode fornecer outra combinação estilos de caixa, chamando o `CComboBoxEx` função de membro [SetExtendedStyle](#setextendedstyle). Com esses estilos, você pode:  
  
-   Pesquisa de cadeia de caracteres do conjunto na lista para diferenciar maiusculas de minúsculas.  
  
-   Criar um controle caixa de combinação que usa a barra ('/'), barra invertida ('\\') e o período ('. ') caracteres como delimitadores de palavras. Isso que os usuários saltar de uma palavra para word, usando o atalho de teclado CTRL + seta.  
  
-   Defina a caixa de combinação controle de caixa para exibir ou não exibir uma imagem. Se nenhuma imagem for exibida, a caixa de combinação pode remover o recuo do texto que acomoda uma imagem.  
  
-   Crie um controle de caixa de combinação estreita, incluindo dimensioná-la para que ele Recorta a caixa de combinação mais ampla que ele contém.  
  
 Esses sinalizadores de estilo são descritos mais detalhadamente em [CComboBoxEx usando](../../mfc/using-ccomboboxex.md).  
  
## <a name="item-retention-and-callback-item-attributes"></a>Retenção de itens e os atributos de Item de retorno de chamada  
 Informações do item, como índices de itens e imagens, valores de recuo e cadeias de caracteres de texto, são armazenadas na estrutura Win32 [COMBOBOXEXITEM](/windows/desktop/api/commctrl/ns-commctrl-tagcomboboxexitema), conforme descrito no SDK do Windows. A estrutura também contém membros que correspondem aos sinalizadores de retorno de chamada.  
  
 Para obter uma discussão detalhada, conceitual, consulte [CComboBoxEx usando](../../mfc/using-ccomboboxex.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CComboBox](../../mfc/reference/ccombobox-class.md)  
  
 `CComboBoxEx`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="ccomboboxex"></a>  CComboBoxEx::CComboBoxEx  
 Chame essa função de membro para criar um `CComboBoxEx` objeto.  
  
```  
CComboBoxEx();
```  
  
##  <a name="create"></a>  CComboBoxEx::Create  
 Cria a caixa de combinação e anexa-o para o `CComboBoxEx` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwStyle*  
 Especifica a combinação de estilos de caixa de combinação aplicada à caixa de combinação. Ver **comentários** abaixo para obter mais informações sobre estilos.  
  
 *Rect*  
 Uma referência a um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, que é a posição e tamanho da caixa de combinação.  
  
 *pParentWnd*  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser NULL.  
  
 *nID*  
 Especifica a ID do controle. da caixa de combinação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto foi criado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Criar um `CComboBoxEx` objeto em duas etapas:  
  
1.  Chame [CComboBoxEx](#ccomboboxex) para construir um `CComboBoxEx` objeto.  
  
2.  Chame essa função de membro, que cria a caixa de combinação estendida do Windows e anexa-o para o `CComboBoxEx` objeto.  
  
 Quando você chama `Create`, MFC inicializa os controles comuns.  
  
 Quando você cria a caixa de combinação, você pode especificar qualquer ou todos os seguintes estilos de caixa de combinação:  
  
- CBS_SIMPLE  
  
- CBS_DROPDOWN  
  
- CBS_DROPDOWNLIST  
  
- CBS_AUTOHSCROLL  
  
- WS_CHILD  
  
 Todos os outros estilos passados ao criar a janela são ignorados. O `ComboBoxEx` controle também dá suporte a estilos estendidos que fornecem recursos adicionais. Esses estilos são descritos em [ComboBoxEx controlar estilos estendidos](/windows/desktop/Controls/comboboxex-control-extended-styles), no SDK do Windows. Definir esses estilos chamando [SetExtendedStyle](#setextendedstyle).  
  
 Se você quiser usar estilos estendidos do windows com o seu controle, chame [CreateEx](#createex) em vez de `Create`.  
  
##  <a name="createex"></a>  CComboBoxEx::CreateEx  
 Chame essa função para criar um controle de caixa de combinação estendido (uma janela filho) e associá-lo com o `CComboBoxEx` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwExStyle*  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.  
  
 *dwStyle*  
 Estilo do controle de caixa de combinação. Ver [criar](#create) para obter uma lista de estilos.  
  
 *Rect*  
 Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.  
  
 *pParentWnd*  
 Um ponteiro para a janela que é o pai do controle.  
  
 *nID*  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de `Create` para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
 `CreateEx` cria o controle com os estilos estendidos do Windows especificados pela *dwExStyle*. Você deve definir estilos estendidos específicos para um controle de caixa de combinação estendida usando [SetExtendedStyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como WS_EX_CONTEXTHELP, mas use `SetExtendedStyle` para definir esses estilos como CBES_EX_CASESENSITIVE. Para obter mais informações, consulte os estilos descritos no tópico [estilos estendidos de controle ComboBoxEx](/windows/desktop/Controls/comboboxex-control-extended-styles) no SDK do Windows.  
  
##  <a name="deleteitem"></a>  CComboBoxEx::DeleteItem  
 Remove um item de um `ComboBoxEx` controle.  
  
```  
int DeleteItem(int iIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iIndex*  
 Índice baseado em zero do item a ser removido.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens restantes no controle. Se *iIndex* é inválido, a função retorna CB_ERR.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a funcionalidade da mensagem [CBEM_DELETEITEM](/windows/desktop/Controls/cbem-deleteitem), conforme descrito no SDK do Windows. Quando você chama DeleteItem, uma [WM_NOTIFY](https://msdn.microsoft.com/library/windows/desktop/bb775583) mensagem com notificação CBEN_DELETEITEM será enviada para a janela pai.  
  
##  <a name="getcomboboxctrl"></a>  CComboBoxEx::GetComboBoxCtrl  
 Chame essa função de membro para obter um ponteiro para um controle de caixa de combinação em um `CComboBoxEx` objeto.  
  
```  
CComboBox* GetComboBoxCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CComboBox` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CComboBoxEx` controle consiste em uma janela pai, que encapsula um `CComboBox`.  
  
 O `CComboBox` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="geteditctrl"></a>  CComboBoxEx::GetEditCtrl  
 Chame essa função de membro para obter um ponteiro para o controle de edição para uma caixa de combinação.  
  
```  
CEdit* GetEditCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CEdit](../../mfc/reference/cedit-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Um `CComboBoxEx` controle usa uma caixa de edição quando ele é criado com o estilo CBS_DROPDOWN.  
  
 O `CEdit` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="getextendedstyle"></a>  CComboBoxEx::GetExtendedStyle  
 Chame essa função de membro para obter os estilos estendidos usados para um `CComboBoxEx` controle.  
  
```  
DWORD GetExtendedStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor DWORD que contém os estilos estendidos que são usados para o controle de caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Ver [estilos estendidos de controle ComboBoxEx](/windows/desktop/Controls/comboboxex-control-extended-styles) no SDK do Windows para obter mais informações sobre esses estilos.  
  
##  <a name="getimagelist"></a>  CComboBoxEx::GetImageList  
 Chame essa função de membro para obter um ponteiro para a lista de imagens usada por um `CComboBoxEx` controle.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto. Se ele falhar, essa função membro retorna NULL.  
  
### <a name="remarks"></a>Comentários  
 O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="getitem"></a>  CComboBoxEx::GetItem  
 Item de recupera informações para um determinado `ComboBoxEx` item.  
  
```  
BOOL GetItem(COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCBItem*  
 Um ponteiro para um [COMBOBOXEXITEM](/windows/desktop/api/commctrl/ns-commctrl-tagcomboboxexitema) estrutura que receberá as informações do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a funcionalidade da mensagem [CBEM_GETITEM](/windows/desktop/Controls/cbem-getitem), conforme descrito no SDK do Windows.  
  
##  <a name="haseditchanged"></a>  CComboBoxEx::HasEditChanged  
 Determina se o usuário alterou o conteúdo do `ComboBoxEx` Editar controle digitando.  
  
```  
BOOL HasEditChanged();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário digitou na caixa de edição do controle; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a funcionalidade da mensagem [CBEM_HASEDITCHANGED](/windows/desktop/Controls/cbem-haseditchanged), conforme descrito no SDK do Windows.  
  
##  <a name="insertitem"></a>  CComboBoxEx::InsertItem  
 Insere um novo item em uma `ComboBoxEx` controle.  
  
```  
int InsertItem(const COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCBItem*  
 Um ponteiro para um [COMBOBOXEXITEM](/windows/desktop/api/commctrl/ns-commctrl-tagcomboboxexitema) estrutura que receberá as informações do item. Essa estrutura contém os valores de sinalizador de retorno de chamada para o item.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice no qual o novo item foi inserido se for bem-sucedido; Caso contrário,-1.  
  
### <a name="remarks"></a>Comentários  
 Quando você chama `InsertItem`, um [WM_NOTIFY](https://msdn.microsoft.com/library/windows/desktop/bb775583) da mensagem com [CBEN_INSERTITEM](/windows/desktop/Controls/cben-insertitem) notificação será enviada para a janela pai.  
  
##  <a name="setextendedstyle"></a>  CComboBoxEx::SetExtendedStyle  
 Chame essa função de membro para definir os estilos estendidos usados para uma caixa de combinação estendida do controle.  
  
```  
DWORD SetExtendedStyle(
    DWORD dwExMask,  
    DWORD dwExStyles);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwExMask*  
 Um valor DWORD que indica quais estilos no *dwExStyles* são que serão afetadas. Somente os estilos estendidos na *dwExMask* será alterado. Todos os outros estilos serão mantidos como está. Se esse parâmetro for zero, então todos os estilos no *dwExStyles* serão afetados.  
  
 *dwExStyles*  
 Um valor DWORD que contém o controle de caixa de combinação estendido estilos a ser definido para o controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor DWORD que contém os estilos estendidos usados anteriormente para o controle.  
  
### <a name="remarks"></a>Comentários  
 Ver [estilos estendidos de controle ComboBoxEx](/windows/desktop/Controls/comboboxex-control-extended-styles) no SDK do Windows para obter mais informações sobre esses estilos.  
  
 Para criar uma caixa de combinação estendida do controle com os estilos estendidos do windows, use [CreateEx](#createex).  
  
##  <a name="setimagelist"></a>  CComboBoxEx::SetImageList  
 Define uma lista de imagens para um `ComboBoxEx` controle.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pImageList*  
 Um ponteiro para um `CImageList` objeto que contém as imagens a serem usadas com o `CComboBoxEx` controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto que contém as imagens usadas anteriormente pelo `CComboBoxEx` controle. NULL se nenhuma lista de imagens foi definida anteriormente.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a funcionalidade da mensagem [CBEM_SETIMAGELIST](/windows/desktop/Controls/cbem-setimagelist), conforme descrito no SDK do Windows. Se você alterar a altura do controle de edição padrão, chame a função Win32 [SetWindowPos](/windows/desktop/api/winuser/nf-winuser-setwindowpos) redimensione seu controle depois de chamar `SetImageList`, ou ele não será exibido corretamente.  
  
 O `CImageList` objeto apontado pelo valor de retorno é um objeto temporário e é destruído durante o próximo tempo de processamento ocioso.  
  
##  <a name="setitem"></a>  CComboBoxEx::SetItem  
 Define os atributos de um item em um `ComboBoxEx` controle.  
  
```  
BOOL SetItem(const COMBOBOXEXITEM* pCBItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pCBItem*  
 Um ponteiro para um [COMBOBOXEXITEM](/windows/desktop/api/commctrl/ns-commctrl-tagcomboboxexitema) estrutura que receberá as informações do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a funcionalidade da mensagem [CBEM_SETITEM](/windows/desktop/Controls/cbem-setitem), conforme descrito no SDK do Windows.  
  
##  <a name="setwindowtheme"></a>  CComboBoxEx::SetWindowTheme  
 Define o estilo visual da caixa de combinação estendida, de controle de caixa.  
  
```  
HRESULT SetWindowTheme(LPCWSTR pszSubAppName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszSubAppName*  
 Um ponteiro para uma cadeia de caracteres Unicode que contém o estilo visual da caixa de combinação estendido para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno não é usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade dos [CBEM_SETWINDOWTHEME](/windows/desktop/Controls/cbem-setwindowtheme) da mensagem, conforme descrito no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)
