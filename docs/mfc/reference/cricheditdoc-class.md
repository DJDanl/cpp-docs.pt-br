---
title: Classe CRichEditDoc | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRichEditDoc
- AFXRICH/CRichEditDoc
- AFXRICH/CRichEditDoc::CreateClientItem
- AFXRICH/CRichEditDoc::GetStreamFormat
- AFXRICH/CRichEditDoc::GetView
- AFXRICH/CRichEditDoc::m_bRTF
dev_langs:
- C++
helpviewer_keywords:
- document/view architecture, rich edit controls
- OLE containers, rich edit
- documents, rich edit
- rich edit controls, OLE container
- CRichEditDoc class
ms.assetid: c936ec18-d516-49d4-b7fb-c9aa0229eddc
caps.latest.revision: 24
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
ms.openlocfilehash: c7233c27c92c6dc689853e1913bb26f0bb5941fa
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cricheditdoc-class"></a>Classe CRichEditDoc
Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição avançada dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditDoc : public COleServerDoc  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditDoc::CreateClientItem](#createclientitem)|Chamado para executar a limpeza do documento.|  
|[CRichEditDoc::GetStreamFormat](#getstreamformat)|Indica se o fluxo de entrada e saída devem incluir informações de formatação.|  
|[CRichEditDoc::GetView](#getview)|Recupera o asssociated [CRichEditView](../../mfc/reference/cricheditview-class.md) objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditDoc::m_bRTF](#m_brtf)|Indica se o fluxo de e/s deve incluir a formatação.|  
  
## <a name="remarks"></a>Comentários  
 "Controle rich edit" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE incorporados. Controles de edição avançados fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView`mantém o texto e as características de formatação de texto. `CRichEditDoc`mantém a lista de itens de cliente no modo de exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner para os itens de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter um exemplo do uso de um documento de edição rica em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)  
  
 [COleServerDoc](../../mfc/reference/coleserverdoc-class.md)  
  
 `CRichEditDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrich.h  
  
##  <a name="createclientitem"></a>CRichEditDoc::CreateClientItem  
 Chame essa função para criar um `CRichEditCntrItem` do objeto e adicioná-la a esse documento.  
  
```  
virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo = NULL) const = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *preo*  
 Ponteiro para uma [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído em torno deste item OLE. Se *preo* é **nulo**, o novo item do cliente está vazio.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um novo [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto que foi adicionado a este documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função não executa qualquer inicialização OLE.  
  
 Para obter mais informações, consulte o [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getstreamformat"></a>CRichEditDoc::GetStreamFormat  
 Chame essa função para determinar o formato de texto para o conteúdo da edição avançada de streaming.  
  
```  
int GetStreamFormat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos sinalizadores a seguir:  
  
- `SF_TEXT`Indica que o controle rich edit não mantém informações de formatação.  
  
- `SF_RTF`Indica que o controle rich edit manter informações de formatação.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno se baseia o [m_bRTF](#m_brtf) membro de dados. Esta função retorna `SF_RTF` se `m_bRTF` é **TRUE**; caso contrário, `SF_TEXT`.  
  
##  <a name="getview"></a>CRichEditDoc::GetView  
 Chame essa função para acessar o [CRichEditView](../../mfc/reference/cricheditview-class.md) objeto associado a esse `CRichEditDoc` objeto.  
  
```  
virtual CRichEditView* GetView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o `CRichEditView` objeto associado ao documento.  
  
### <a name="remarks"></a>Comentários  
 O texto e informações de formatação contidos dentro de `CRichEditView` objeto. O `CRichEditDoc` objeto mantém os itens OLE para serialização. Deve haver apenas um `CRichEditView` para cada `CRichEditDoc`.  
  
##  <a name="m_brtf"></a>CRichEditDoc::m_bRTF  
 Quando **TRUE**, indica que [CRichEditCtrl::StreamIn](../../mfc/reference/cricheditctrl-class.md#streamin) e [CRichEditCtrl::StreamOut](../../mfc/reference/cricheditctrl-class.md#streamout) deve armazenar características de formatação de caractere e de parágrafo.  
  
```  
BOOL m_bRTF;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)   
 [Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md)

