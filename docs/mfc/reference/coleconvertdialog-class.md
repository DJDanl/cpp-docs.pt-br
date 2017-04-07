---
title: Classe COleConvertDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleConvertDialog
- AFXODLGS/COleConvertDialog
- AFXODLGS/COleConvertDialog::COleConvertDialog
- AFXODLGS/COleConvertDialog::DoConvert
- AFXODLGS/COleConvertDialog::DoModal
- AFXODLGS/COleConvertDialog::GetClassID
- AFXODLGS/COleConvertDialog::GetDrawAspect
- AFXODLGS/COleConvertDialog::GetIconicMetafile
- AFXODLGS/COleConvertDialog::GetSelectionType
- AFXODLGS/COleConvertDialog::m_cv
dev_langs:
- C++
helpviewer_keywords:
- COleConvertDialog class
- OLE Convert dialog box
- dialog boxes, OLE
- OLE dialog boxes, Convert
- Convert dialog box
ms.assetid: a7c57714-31e8-4b78-834d-8ddd1b856a1c
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
ms.openlocfilehash: 6db5caf443e7f71c58e2c65b46794c2c9d246d38
ms.lasthandoff: 02/25/2017

---
# <a name="coleconvertdialog-class"></a>Classe COleConvertDialog
Para obter mais informações, consulte o [OLEUICONVERT](http://msdn.microsoft.com/library/windows/desktop/ms686657) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleConvertDialog : public COleDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleConvertDialog::COleConvertDialog](#coleconvertdialog)|Constrói um objeto `COleConvertDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleConvertDialog::DoConvert](#doconvert)|Executa a conversão especificada na caixa de diálogo.|  
|[COleConvertDialog::DoModal](#domodal)|Exibe a caixa de diálogo de Item de alteração OLE.|  
|[COleConvertDialog::GetClassID](#getclassid)|Obtém o **CLSID** associado ao item escolhido.|  
|[COleConvertDialog::GetDrawAspect](#getdrawaspect)|Especifica se deve desenhar item como um ícone.|  
|[COleConvertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|  
|[COleConvertDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de seleção escolhida.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleConvertDialog::m_cv](#m_cv)|Uma estrutura que controla o comportamento da caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Código do contêiner gerado pelo Assistente de aplicativo usa essa classe.  
  
 Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 [COleDialog](../../mfc/reference/coledialog-class.md)  
  
 `COleConvertDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxodlgs.h  
  
##  <a name="coleconvertdialog"></a>COleConvertDialog::COleConvertDialog  
 Constrói apenas uma `COleConvertDialog` objeto.  
  
```  
explicit COleConvertDialog (
    COleClientItem* pItem,
    DWORD dwFlags = CF_SELECTCONVERTTO,
    CLSID* pClassID = NULL,
    CWnd* pParentWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Aponta para o item a ser convertido ou ativado.  
  
 `dwFlags`  
 Sinalizador de criação, que contém qualquer número de valores combinados usando o bit a bit- ou operador:  
  
- **CF_SELECTCONVERTTO** Especifica que o botão de opção Converter será selecionado inicialmente quando a caixa de diálogo é chamada. Esse é o padrão.  
  
- **CF_SELECTACTIVATEAS** Especifica que o botão de opção Ativar como será selecionado inicialmente quando a caixa de diálogo é chamada.  
  
- **CF_SETCONVERTDEFAULT** Especifica que a classe cuja **CLSID** é especificado pelo **clsidConvertDefault** membro do `m_cv` estrutura será usada como a seleção padrão na caixa de listagem de classe ao converter em botão de opção está selecionado.  
  
- **CF_SETACTIVATEDEFAULT** Especifica que a classe cuja **CLSID** é especificado pelo **clsidActivateDefault** membro do `m_cv` estrutura será usada como a seleção padrão na caixa de listagem de classe quando o botão de opção Ativar como está selecionado.  
  
- **CF_SHOWHELPBUTTON** Especifica que o botão de Ajuda será exibido quando a caixa de diálogo é chamada.  
  
 `pClassID`  
 Aponta para o CLSID do item a ser convertido ou ativados. Se **nulo**, o **CLSID** associado `pItem` será usado.  
  
 `pParentWnd`  
 Aponta para o objeto de janela pai ou proprietário (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for **nulo**, a janela pai da caixa de diálogo é definida para a janela principal do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 Para exibir a caixa de diálogo, chame o [DoModal](#domodal) função.  
  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) e [OLEUICONVERT](http://msdn.microsoft.com/library/windows/desktop/ms686657) estrutura.  
  
##  <a name="doconvert"></a>COleConvertDialog::DoConvert  
 Chame essa função, depois de retornar com êxito do [DoModal](#domodal), para converter ou ativar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md).  
  
```  
BOOL DoConvert(COleClientItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Aponta para o item a ser convertido ou ativado. Não pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O item é convertido ou ativado de acordo com as informações selecionadas pelo usuário na caixa de diálogo Converter.  
  
##  <a name="domodal"></a>COleConvertDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo converter OLE.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Status de conclusão para a caixa de diálogo. Um dos seguintes valores:  
  
- **IDOK** se a caixa de diálogo foi exibida com êxito.  
  
- **IDCANCEL** se o usuário cancelou a caixa de diálogo.  
  
- **IDABORT** se ocorreu um erro. Se **IDABORT** é retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIConvert](http://msdn.microsoft.com/library/windows/desktop/ms680694) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar os vários controles de caixa de diálogo definindo membros do [m_cv](#m_cv) estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Se `DoModal` retorna **IDOK**, você pode chamar outro membro funções para recuperar as configurações ou informações que foi inseridas pelo usuário na caixa de diálogo.  
  
##  <a name="getclassid"></a>COleConvertDialog::GetClassID  
 Chame essa função para obter o **CLSID** associado ao item o usuário selecionado na caixa de diálogo Converter.  
  
```  
REFCLSID GetClassID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O **CLSID** associado ao item selecionado na caixa de diálogo Converter.  
  
### <a name="remarks"></a>Comentários  
 Essa função somente depois de chamada [DoModal](#domodal) retorna **IDOK**.  
  
 Para obter mais informações, consulte [chave CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdrawaspect"></a>COleConvertDialog::GetDrawAspect  
 Chame essa função para determinar se o usuário optar por exibir o item selecionado como um ícone.  
  
```  
DVASPECT GetDrawAspect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O método necessário para processar o objeto.  
  
- `DVASPECT_CONTENT`Retornado se a caixa de seleção Exibir como ícone não foi selecionada.  
  
- `DVASPECT_ICON`Retornado se a caixa de seleção Exibir como ícone foi verificada.  
  
### <a name="remarks"></a>Comentários  
 Essa função somente depois de chamada [DoModal](#domodal) retorna **IDOK**.  
  
 Para obter mais informações sobre os aspectos de desenho, consulte o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) na estrutura de dados de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="geticonicmetafile"></a>COleConvertDialog::GetIconicMetafile  
 Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.  
  
```  
HGLOBAL GetIconicMetafile() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o metarquivo contendo o aspecto icônico do item selecionado, se a caixa de seleção Exibir como ícone foi marcada quando a caixa de diálogo foi ignorada, escolhendo **Okey**; caso contrário, **nulo**.  
  
##  <a name="getselectiontype"></a>COleConvertDialog::GetSelectionType  
 Chame essa função para determinar o tipo de conversão selecionado na caixa de diálogo Converter.  
  
```  
UINT GetSelectionType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tipo de seleção feita.  
  
### <a name="remarks"></a>Comentários  
 Os valores de tipo de retorno são especificados pelo **seleção** tipo de enumeração declarada no `COleConvertDialog` classe.  
  
```  
enum Selection {
    noConversion,
    convertItem,
    activateAs
    };  
```  
  
 Execute as breves descrições desses valores:  
  
- **COleConvertDialog::noConversion** retornado se a caixa de diálogo foi cancelada ou que o usuário não selecionou nenhuma conversão. Se `COleConvertDialog::DoModal` retornou **IDOK**, é possível que o usuário selecionou um ícone diferente daquele selecionado anteriormente.  
  
- **COleConvertDialog::convertItem** retornado se o botão de opção Converter tiver sido selecionado, o usuário selecionou um item diferente para converter, e `DoModal` retornou **IDOK**.  
  
- **COleConvertDialog::activateAs** retornado se o botão de opção Ativar como tiver sido selecionado, o usuário selecionou um item diferente para ativar, e `DoModal` retornou **IDOK**.  
  
##  <a name="m_cv"></a>COleConvertDialog::m_cv  
 Estrutura do tipo **OLEUICONVERT** usado para controlar o comportamento da caixa de diálogo Converter.  
  
```  
OLEUICONVERT m_cv;  
```  
  
### <a name="remarks"></a>Comentários  
 Membros dessa estrutura podem ser modificados diretamente ou através de funções de membro.  
  
 Para obter mais informações, consulte o [OLEUICONVERT](http://msdn.microsoft.com/library/windows/desktop/ms686657) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDialog](../../mfc/reference/coledialog-class.md)

