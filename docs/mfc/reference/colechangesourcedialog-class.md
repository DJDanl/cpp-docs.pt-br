---
title: Classe COleChangeSourceDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog::COleChangeSourceDialog
- AFXODLGS/COleChangeSourceDialog::DoModal
- AFXODLGS/COleChangeSourceDialog::GetDisplayName
- AFXODLGS/COleChangeSourceDialog::GetFileName
- AFXODLGS/COleChangeSourceDialog::GetFromPrefix
- AFXODLGS/COleChangeSourceDialog::GetItemName
- AFXODLGS/COleChangeSourceDialog::GetToPrefix
- AFXODLGS/COleChangeSourceDialog::IsValidSource
- AFXODLGS/COleChangeSourceDialog::m_cs
dev_langs:
- C++
helpviewer_keywords:
- OLE Change Source dialog box
- COleChangeSourceDialog class
- dialog boxes, OLE
- OLE dialog boxes, Change Source
- OleUIChangeSource structure
ms.assetid: d0e08be7-21ef-45e1-97af-fe27d99e3bac
caps.latest.revision: 22
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 4a1af032b9a10a0262f0267056b675eed7da509c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="colechangesourcedialog-class"></a>Classe COleChangeSourceDialog
Usado para a caixa de diálogo Alterar fonte de dados OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleChangeSourceDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeSourceDialog::COleChangeSourceDialog](#colechangesourcedialog)|Constrói um objeto `COleChangeSourceDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeSourceDialog::DoModal](#domodal)|Exibe a caixa de diálogo Alterar fonte de dados OLE.|  
|[COleChangeSourceDialog::GetDisplayName](#getdisplayname)|Obtém o nome de exibição do código-fonte completo.|  
|[COleChangeSourceDialog::GetFileName](#getfilename)|Obtém o nome do arquivo do nome de origem.|  
|[COleChangeSourceDialog::GetFromPrefix](#getfromprefix)|Obtém o prefixo da origem anterior.|  
|[COleChangeSourceDialog::GetItemName](#getitemname)|Obtém o nome do item do nome de origem.|  
|[COleChangeSourceDialog::GetToPrefix](#gettoprefix)|Obtém o prefixo da nova origem|  
|[COleChangeSourceDialog::IsValidSource](#isvalidsource)|Indica se a fonte é válida.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeSourceDialog::m_cs](#m_cs)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleChangeSourceDialog` quando você deseja chamar essa caixa de diálogo. Após um `COleChangeSourceDialog` objeto foi construído, você pode usar o [m_cs](#m_cs) estrutura para inicializar os valores ou os estados de controles na caixa de diálogo. O `m_cs` estrutura é do tipo [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160). Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte o [DoModal](#domodal) função de membro.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleChangeSourceDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="colechangesourcedialog"></a>COleChangeSourceDialog::COleChangeSourceDialog  
 Essa função constrói uma `COleChangeSourceDialog` objeto.  
  
```  
explicit COleChangeSourceDialog(
    COleClientItem* pItem,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para vinculado [COleClientItem](../../mfc/reference/coleclientitem-class.md) cuja origem é atualizado.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura e [OleUIChangeSource](http://msdn.microsoft.com/library/windows/desktop/ms682497) funcionem em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="domodal"></a>COleChangeSourceDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo Alterar fonte de dados OLE.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIChangeSource](http://msdn.microsoft.com/library/windows/desktop/ms682497) funcionem em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_cs](#m_cs) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar funções para recuperar configurações inserido pelo usuário ou informações de caixa de diálogo membro. A lista a seguir nomes de funções de consulta típica:  
  
- [GetFileName](#getfilename)  
  
- [GetDisplayName](#getdisplayname)  
  
- [GetItemName](#getitemname)  
  
##  <a name="getdisplayname"></a>COleChangeSourceDialog::GetDisplayName  
 Chame essa função para recuperar o nome de exibição completa do item vinculado do cliente.  
  
```  
CString GetDisplayName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome de exibição de fonte completo (moniker) para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.  
  
##  <a name="getfilename"></a>COleChangeSourceDialog::GetFileName  
 Chame essa função para recuperar a parte do moniker do arquivo do nome para exibição para o item do cliente vinculada.  
  
```  
CString GetFileName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte do identificador de origem de arquivo do nome para exibição de fonte de [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.  
  
### <a name="remarks"></a>Comentários  
 O moniker do arquivo junto com o moniker do item fornece o nome de exibição completa.  
  
##  <a name="getfromprefix"></a>COleChangeSourceDialog::GetFromPrefix  
 Chame essa função para obter a cadeia de caracteres de prefixo anterior para a fonte.  
  
```  
CString GetFromPrefix();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cadeia de prefixo anterior da fonte.  
  
### <a name="remarks"></a>Comentários  
 Essa função somente depois de chamada [DoModal](#domodal) retorna **IDOK**.  
  
 Este valor vem diretamente do **lpszFrom** membro o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getitemname"></a>COleChangeSourceDialog::GetItemName  
 Chame essa função para recuperar a parte do moniker do item do nome para exibição para o item do cliente vinculada.  
  
```  
CString GetItemName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A parte do moniker item da fonte de exibição para o [COleClientItem](../../mfc/reference/coleclientitem-class.md) especificado no construtor.  
  
### <a name="remarks"></a>Comentários  
 O moniker do arquivo junto com o moniker do item fornece o nome de exibição completa.  
  
##  <a name="gettoprefix"></a>COleChangeSourceDialog::GetToPrefix  
 Chame essa função para obter a nova cadeia de caracteres de prefixo para a fonte.  
  
```  
CString GetToPrefix();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A nova cadeia de prefixo da origem.  
  
### <a name="remarks"></a>Comentários  
 Essa função somente depois de chamada [DoModal](#domodal) retorna **IDOK**.  
  
 Este valor vem diretamente do **lpszTo** membro o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="m_cs"></a>COleChangeSourceDialog::m_cs  
 Este membro de dados é uma estrutura de tipo [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160).  
  
```  
OLEUICHANGESOURCE m_cs;  
```  
  
### <a name="remarks"></a>Comentários  
 `OLEUICHANGESOURCE`é usado para controlar o comportamento da caixa de diálogo Alterar fonte de dados OLE. Membros dessa estrutura podem ser modificados diretamente.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isvalidsource"></a>COleChangeSourceDialog::IsValidSource  
 Chame essa função para determinar se a nova fonte é válida.  
  
```  
BOOL IsValidSource();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a nova fonte é válida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função somente depois de chamada [DoModal](#domodal) retorna **IDOK**.  
  
 Para obter mais informações, consulte o [OLEUICHANGESOURCE](http://msdn.microsoft.com/library/windows/desktop/ms682160) estrutura em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)

