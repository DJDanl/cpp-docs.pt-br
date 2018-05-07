---
title: Classe CRichEditDoc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CRichEditDoc [MFC], CreateClientItem
- CRichEditDoc [MFC], GetStreamFormat
- CRichEditDoc [MFC], GetView
- CRichEditDoc [MFC], m_bRTF
ms.assetid: c936ec18-d516-49d4-b7fb-c9aa0229eddc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 28b84747a694a62139546f3105f84c9e799b292a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cricheditdoc-class"></a>Classe CRichEditDoc
Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento do MFC.  
  
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
 Um "controle de edição avançada" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE inseridos. Controles de edição avançada fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface de usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView` mantém a característica de formatação de texto e texto. `CRichEditDoc` mantém a lista de itens de cliente que estão no modo de exibição. `CRichEditCntrItem` fornece acesso do lado do contêiner para os itens de cliente OLE.  
  
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
  
##  <a name="createclientitem"></a>  CRichEditDoc::CreateClientItem  
 Chamar essa função para criar um `CRichEditCntrItem` de objeto e adicioná-lo a este documento.  
  
```  
virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo = NULL) const = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *preo*  
 Ponteiro para um [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído em torno deste item OLE. Se *preo* é **nulo**, o novo item do cliente está vazio.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um novo [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto que foi adicionado a este documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função não executa qualquer inicialização OLE.  
  
 Para obter mais informações, consulte o [REOBJECT](http://msdn.microsoft.com/library/windows/desktop/bb787946) estrutura no SDK do Windows.  
  
##  <a name="getstreamformat"></a>  CRichEditDoc::GetStreamFormat  
 Chame essa função para determinar o formato de texto para o conteúdo de edição com formato de streaming.  
  
```  
int GetStreamFormat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos sinalizadores a seguir:  
  
- `SF_TEXT` Indica que o controle rich edit não mantém informações de formatação.  
  
- `SF_RTF` Indica que o controle rich edit manter informações de formatação.  
  
### <a name="remarks"></a>Comentários  
 O valor de retorno se baseia o [m_bRTF](#m_brtf) membro de dados. Essa função retorna `SF_RTF` se `m_bRTF` é **TRUE**; caso contrário, `SF_TEXT`.  
  
##  <a name="getview"></a>  CRichEditDoc::GetView  
 Chamar essa função para acessar o [CRichEditView](../../mfc/reference/cricheditview-class.md) objeto associado a esta `CRichEditDoc` objeto.  
  
```  
virtual CRichEditView* GetView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o `CRichEditView` objeto associado com o documento.  
  
### <a name="remarks"></a>Comentários  
 O texto e as informações de formatação contidos o `CRichEditView` objeto. O `CRichEditDoc` objeto mantém os itens OLE para serialização. Deve haver apenas um `CRichEditView` para cada `CRichEditDoc`.  
  
##  <a name="m_brtf"></a>  CRichEditDoc::m_bRTF  
 Quando **TRUE**, indica que [CRichEditCtrl::StreamIn](../../mfc/reference/cricheditctrl-class.md#streamin) e [CRichEditCtrl::StreamOut](../../mfc/reference/cricheditctrl-class.md#streamout) deve armazenar o parágrafo e características de formatação de caracteres.  
  
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
