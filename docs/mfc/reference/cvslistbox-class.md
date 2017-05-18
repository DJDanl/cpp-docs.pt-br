---
title: Classe CVSListBox | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CVSListBox
- AFXVSLISTBOX/CVSListBox
- AFXVSLISTBOX/CVSListBox::CVSListBox
- AFXVSLISTBOX/CVSListBox::AddItem
- AFXVSLISTBOX/CVSListBox::EditItem
- AFXVSLISTBOX/CVSListBox::GetCount
- AFXVSLISTBOX/CVSListBox::GetItemData
- AFXVSLISTBOX/CVSListBox::GetItemText
- AFXVSLISTBOX/CVSListBox::GetSelItem
- AFXVSLISTBOX/CVSListBox::RemoveItem
- AFXVSLISTBOX/CVSListBox::SelectItem
- AFXVSLISTBOX/CVSListBox::SetItemData
- AFXVSLISTBOX/CVSListBox::GetListHwnd
dev_langs:
- C++
helpviewer_keywords:
- CVSListBox::PreTranslateMessage method
- CVSListBox class
ms.assetid: c79be7b4-46ed-4af8-a41e-68962782d8ef
caps.latest.revision: 30
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4527249fc1a22a1db0623ea46954065fcbd071f4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cvslistbox-class"></a>Classe CVSListBox
O `CVSListBox` classe oferece suporte a um controle de lista editável.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CVSListBox : public CVSListBoxBase  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CVSListBox::CVSListBox](#cvslistbox)|Constrói um objeto `CVSListBox`.|  
|`CVSListBox::~CVSListBox`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CVSListBox::AddItem](#additem)|Adiciona uma cadeia de caracteres a um controle de lista. (Substitui `CVSListBoxBase::AddItem`.)|  
|[CVSListBox::EditItem](#edititem)|Inicia uma operação de edição no texto de um item de controle de lista. (Substitui `CVSListBoxBase::EditItem`.)|  
|[CVSListBox::GetCount](#getcount)|Recupera o número de cadeias de caracteres em um controle de lista editável. (Substitui `CVSListBoxBase::GetCount`.)|  
|[CVSListBox::GetItemData](#getitemdata)|Recupera um valor de 32 bits específicos do aplicativo que está associado um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemData`.)|  
|[CVSListBox::GetItemText](#getitemtext)|Recupera o texto de um item de controle de lista editável. (Substitui `CVSListBoxBase::GetItemText`.)|  
|[CVSListBox::GetSelItem](#getselitem)|Retorna o índice baseado em zero do item atualmente selecionado em um controle de lista editável. (Substitui `CVSListBoxBase::GetSelItem`.)|  
|`CVSListBox::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. Para obter mais informações e sintaxe de método, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CVSListBoxBase::PreTranslateMessage`.)|  
|[CVSListBox::RemoveItem](#removeitem)|Remove um item de um controle de lista editável. (Substitui `CVSListBoxBase::RemoveItem`.)|  
|[CVSListBox::SelectItem](#selectitem)|Seleciona uma cadeia de caracteres de controle de lista editável. (Substitui `CVSListBoxBase::SelectItem`.)|  
|[CVSListBox::SetItemData](#setitemdata)|Associa um valor de 32 bits específico do aplicativo com um item de controle de lista editável. (Substitui `CVSListBoxBase::SetItemData`.)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CVSListBox::GetListHwnd](#getlisthwnd)|Retorna o identificador para o controle de exibição de lista incorporada atual.|  
  
## <a name="remarks"></a>Comentários  
 O `CVSListBox` classe fornece um conjunto de botões de edição que permitem ao usuário criar, modificar, excluir ou reorganizar os itens em um controle de lista.  
  
 A seguir está uma imagem do controle de lista editável. A segunda entrada de lista, é intitulada "Item2", é selecionada para edição.  
  
 ![Controle CVSListBox](../../mfc/reference/media/cvslistbox.png "cvslistbox")  
  
 Se você usar o editor de recursos para adicionar um controle de lista editável, observe que o **Toolbox** painel do editor não oferece um controle de lista editável predefinida. Em vez disso, adicione um controle estático, como o **caixa de grupo** controle. A estrutura usa o controle estático como um espaço reservado para especificar o tamanho e a posição do controle de lista editável.  
  
 Para usar um controle de lista editável em um modelo de caixa de diálogo, declarar uma `CVSListBox` variável em sua classe de caixa de diálogo. Para oferecer suporte a troca de dados entre a variável e o controle, defina uma `DDX_Control` entrada macro o `DoDataExchange` método da caixa de diálogo. Por padrão, o controle de lista editável é criado sem botões de edição. Use o método CVSListBoxBase::SetStandardButtons herdado para habilitar os botões Editar.  
  
 Para obter mais informações, consulte o diretório de exemplos, o `New Controls` de exemplo, os arquivos Page3.cpp e Page3.h.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CStatic](../../mfc/reference/cstatic-class.md)  
  
 `CVSListBoxBase`  
  
 [CVSListBox](../../mfc/reference/cvslistbox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxvslistbox.h  
  
##  <a name="additem"></a>CVSListBox::AddItem  
 Adiciona uma cadeia de caracteres a um controle de lista.  
  
```  
virtual int AddItem(
    const CString& strIext,  
    DWORD_PTR dwData=0,  
    int iIndex=-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strIext`  
 Uma referência a uma cadeia de caracteres.  
  
 [in] `dwData`  
 Um valor de 32 bits específicos do aplicativo que está associado com a cadeia de caracteres. O valor padrão é 0.  
  
 [in] `iIndex`  
 O índice baseado em zero da posição que irá conter a cadeia de caracteres. Se o `iIndex` parâmetro é -1, a cadeia de caracteres é adicionada ao final da lista. O valor padrão é -1.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da posição da cadeia de caracteres no controle de lista.  
  
### <a name="remarks"></a>Comentários  
 Use o [CVSListBox::GetItemData](#getitemdata) método para recuperar o valor especificado pelo `dwData` parâmetro. Esse valor pode ser um inteiro de aplicativo específico ou um ponteiro para outros dados.  
  
##  <a name="cvslistbox"></a>CVSListBox::CVSListBox  
 Constrói um objeto `CVSListBox`.  
  
```  
CVSListBox();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="edititem"></a>CVSListBox::EditItem  
 Inicia uma operação de edição no texto de um item de controle de lista.  
  
```  
virtual BOOL EditItem(int iIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 Índice baseado em zero de um item de controle de lista.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a operação de edição é iniciado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O usuário inicia uma operação de edição clicando duas vezes o rótulo de um item ou pressionando o **F2** ou **SPACEBAR** chave quando um item tem o foco.  
  
##  <a name="getcount"></a>CVSListBox::GetCount  
 Recupera o número de cadeias de caracteres em um controle de lista editável.  
  
```  
virtual int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na lista de controle.  
  
### <a name="remarks"></a>Comentários  
 Observe que a contagem é maior do que o valor de índice do último item porque o índice é baseado em zero.  
  
##  <a name="getitemdata"></a>CVSListBox::GetItemData  
 Recupera um valor de 32 bits específicos do aplicativo que está associado um item de controle de lista editável.  
  
```  
virtual DWORD_PTR GetItemData(int iIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice com base em zero de um item de controle de lista editável.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 32 bits que está associado com o item especificado.  
  
### <a name="remarks"></a>Comentários  
 Use o [CVSListBox::SetItemData](#setitemdata) ou [CVSListBox::AddItem](#additem) método para associar o valor de 32 bits com o item de controle de lista. Esse valor pode ser um inteiro de aplicativo específico ou um ponteiro para outros dados.  
  
##  <a name="getitemtext"></a>CVSListBox::GetItemText  
 Recupera o texto de um item de controle de lista editável.  
  
```  
virtual CString GetItemText(int iIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice com base em zero de um item de controle de lista editável.  
  
### <a name="return-value"></a>Valor de retorno  
 A [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto do item especificado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getlisthwnd"></a>CVSListBox::GetListHwnd  
 Retorna o identificador para o controle de exibição de lista incorporada atual.  
  
```  
virtual HWND GetListHwnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o controle de exibição de lista incorporada.  
  
### <a name="remarks"></a>Comentários  
 Use este método para recuperar um identificador para o controle de exibição de lista incorporada que ofereça suporte a `CVSListBox` classe.  
  
##  <a name="getselitem"></a>CVSListBox::GetSelItem  
 Retorna o índice baseado em zero do item atualmente selecionado em um controle de lista editável.  
  
```  
virtual int GetSelItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se esse método for bem-sucedida, o índice baseado em zero do item atualmente selecionado; Caso contrário, retornará -1.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removeitem"></a>CVSListBox::RemoveItem  
 Remove um item de um controle de lista editável.  
  
```  
virtual BOOL RemoveItem(int iIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice com base em zero de um item de controle de lista editável.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o item especificado for removido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="selectitem"></a>CVSListBox::SelectItem  
 Seleciona uma cadeia de caracteres de controle de lista editável.  
  
```  
virtual BOOL SelectItem(int iItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iItem`  
 O índice com base em zero de um item de controle de lista editável.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método seleciona o item especificado e se for necessário, o item é movido para a exibição.  
  
##  <a name="setitemdata"></a>CVSListBox::SetItemData  
 Associa um valor de 32 bits específico do aplicativo com um item de controle de lista editável.  
  
```  
virtual void SetItemData(
    int iIndex,  
    DWORD_PTR dwData);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 O índice com base em zero de um item de controle de lista editável.  
  
 [in] `dwData`  
 Um valor de 32 bits. Esse valor pode ser um inteiro de aplicativo específico ou um ponteiro para outros dados.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

