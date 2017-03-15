---
title: Classe COleChangeIconDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleChangeIconDialog
dev_langs:
- C++
helpviewer_keywords:
- OLE dialog boxes, Change Icon
- OLE Change Icon dialog box
- dialog boxes, OLE
- COleChangeIconDialog class
- Change Icon dialog box
ms.assetid: 8d6e131b-ddbb-4dff-a432-f239efda8e3d
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 07dfd7995bbbdb0f52f55dceedc318d8d702111b
ms.lasthandoff: 02/25/2017

---
# <a name="colechangeicondialog-class"></a>Classe COleChangeIconDialog
Usado para a caixa de diálogo OLE alterar ícone.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleChangeIconDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::COleChangeIconDialog](#colechangeicondialog)|Constrói um objeto `COleChangeIconDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::DoChangeIcon](#dochangeicon)|Executa a alteração especificada na caixa de diálogo.|  
|[COleChangeIconDialog::DoModal](#domodal)|Exibe a caixa de diálogo OLE 2 alterar ícone.|  
|[COleChangeIconDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleChangeIconDialog::m_ci](#m_ci)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Criar um objeto da classe `COleChangeIconDialog` quando você deseja chamar essa caixa de diálogo. Após um `COleChangeIconDialog` objeto foi construído, você pode usar o [m_ci](#m_ci) estrutura para inicializar os valores ou os estados de controles na caixa de diálogo. O `m_ci` estrutura é do tipo **OLEUICHANGEICON**. Para obter mais informações sobre como usar essa classe de caixa de diálogo, consulte o [DoModal](#domodal) função de membro.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](http://msdn.microsoft.com/library/windows/desktop/ms680098) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleChangeIconDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="a-namecolechangeicondialoga--colechangeicondialogcolechangeicondialog"></a><a name="colechangeicondialog"></a>COleChangeIconDialog::COleChangeIconDialog  
 Essa função só constrói uma `COleChangeIconDialog` objeto.  
  
```  
explicit COleChangeIconDialog(
    COleClientItem* pItem,  
    DWORD dwFlags = CIF_SELECTCURRENT,  
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Aponta para o item a ser convertido.  
  
 `dwFlags`  
 Sinalizador de criação, que contém qualquer número de valores combinados usando o bit a bit- ou operador:  
  
- **CIF_SELECTCURRENT** Especifica que o botão de opção atual seja selecionado inicialmente quando a caixa de diálogo é chamada. Esse é o padrão.  
  
- **CIF_SELECTDEFAULT** Especifica que o botão de opção padrão será selecionado inicialmente quando a caixa de diálogo é chamada.  
  
- **CIF_SELECTFROMFILE** Especifica que o botão de opção de arquivo será selecionado inicialmente quando a caixa de diálogo é chamada.  
  
- **CIF_SHOWHELP** Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.  
  
- **CIF_USEICONEXE** Especifica que o ícone deve ser extraído do executável especificado no **szIconExe** campo de [m_ci](#m_ci) em vez de recuperada do tipo. Isso é útil para incorporação ou vinculação de arquivos não são OLE.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](http://msdn.microsoft.com/library/windows/desktop/ms680098) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namedochangeicona--colechangeicondialogdochangeicon"></a><a name="dochangeicon"></a>COleChangeIconDialog::DoChangeIcon  
 Chame essa função para alterar o ícone que representa o item para aquele selecionado na caixa de diálogo após [DoModal](#domodal) retorna **IDOK**.  
  
```  
BOOL DoChangeIcon(COleClientItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Aponta para o item cujo ícone está mudando.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a alteração for bem-sucedida; Caso contrário, 0.  
  
##  <a name="a-namedomodala--colechangeicondialogdomodal"></a><a name="domodal"></a>COleChangeIconDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo OLE alterar ícone.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o `COleDialog::GetLastError` a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIChangeIcon](http://msdn.microsoft.com/library/windows/desktop/ms688307) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_ci](#m_ci) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar outro membro funções para recuperar as configurações ou informações que foi inseridas pelo usuário na caixa de diálogo.  
  
##  <a name="a-namegeticonicmetafilea--colechangeicondialoggeticonicmetafile"></a><a name="geticonicmetafile"></a>COleChangeIconDialog::GetIconicMetafile  
 Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.  
  
```  
HGLOBAL GetIconicMetafile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o metarquivo contendo o aspecto icônico do ícone novo, se a caixa de diálogo foi liberada escolhendo **Okey**; caso contrário, o ícone como ele estava antes da exibição da caixa de diálogo.  
  
##  <a name="a-namemcia--colechangeicondialogmci"></a><a name="m_ci"></a>COleChangeIconDialog::m_ci  
 Estrutura do tipo **OLEUICHANGEICON** usado para controlar o comportamento da caixa de diálogo Alterar ícone.  
  
```  
OLEUICHANGEICON m_ci;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUICHANGEICON](http://msdn.microsoft.com/library/windows/desktop/ms680098) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)

