---
title: Classe COleLinkingDoc | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleLinkingDoc
- AFXOLE/COleLinkingDoc
- AFXOLE/COleLinkingDoc::COleLinkingDoc
- AFXOLE/COleLinkingDoc::Register
- AFXOLE/COleLinkingDoc::Revoke
- AFXOLE/COleLinkingDoc::OnFindEmbeddedItem
- AFXOLE/COleLinkingDoc::OnGetLinkedItem
dev_langs:
- C++
helpviewer_keywords:
- OLE containers, client items
- COleLinkingDoc class
ms.assetid: 9f547f35-2f95-427f-b9c0-85c31940198b
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: acdfde1413d5ff93efc63dbbf211881f71cf624e
ms.lasthandoff: 02/25/2017

---
# <a name="colelinkingdoc-class"></a>Classe COleLinkingDoc
A classe base para documentos de contêiner OLE que dão suporte a vinculação para os itens inseridos que elas contêm.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleLinkingDoc : public COleDocument  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinkingDoc::COleLinkingDoc](#colelinkingdoc)|Constrói um objeto `COleLinkingDoc`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinkingDoc::Register](#register)|Registra o documento com as DLLs do sistema OLE.|  
|[COleLinkingDoc::Revoke](#revoke)|Revoga o registro do documento.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleLinkingDoc::OnFindEmbeddedItem](#onfindembeddeditem)|Localiza o item incorporado especificado.|  
|[COleLinkingDoc::OnGetLinkedItem](#ongetlinkeditem)|Localiza o item vinculado especificado.|  
  
## <a name="remarks"></a>Comentários  
 Um aplicativo de contêiner que dá suporte à vinculação para itens inseridos é chamado de "recipiente de link". O [OCLIENT](../../visual-cpp-samples.md) aplicativo de exemplo é um exemplo de um contêiner de link.  
  
 Quando a fonte de um item vinculado é um item inserido em outro documento, que que contém o documento deve ser carregado para que o item inserido a ser editada. Por esse motivo, um contêiner de link deve ser capaz de ser iniciada por outro aplicativo de contêiner quando o usuário deseja editar a origem de um item vinculado. Seu aplicativo deve usar também o [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) de classe para que ele possa criar documentos quando iniciado por meio de programação.  
  
 Para tornar seu contêiner de um contêiner de link, derive sua classe de documento da `COleLinkingDoc` em vez de [COleDocument](../../mfc/reference/coledocument-class.md). Assim como acontece com qualquer outro contêiner OLE, você deve projetar sua classe para armazenar o aplicativo dados nativos, bem como os itens inseridos ou vinculados. Além disso, você deve criar estruturas de dados para armazenar seus dados nativos. Se você definir um `CDocItem`-classe derivada para seu aplicativo nativo dados, você pode usar a interface definida pelo `COleDocument` para armazenar seus dados nativos, bem como seus dados OLE.  
  
 Para permitir que o aplicativo ser iniciado por meio de programação por outro contêiner, declare um `COleTemplateServer` objeto como um membro do seu aplicativo `CWinApp`-classe derivada:  
  
 [!code-cpp[NVC_MFCOleContainer&#23;](../../mfc/codesnippet/cpp/colelinkingdoc-class_1.h)]  
  
 No `InitInstance` função de membro de seu `CWinApp`-derivado da classe, crie um modelo de documento e especifique seu `COleLinkingDoc`-derivado à classe de documento:  
  
 [!code-cpp[NVC_MFCOleContainer&#24;](../../mfc/codesnippet/cpp/colelinkingdoc-class_2.cpp)]  
  
 Conectar-se a `COleTemplateServer` objeto para os modelos de documento chamando o objeto `ConnectTemplate` função de membro e registrar todas as classes de objetos com o sistema OLE chamando **COleTemplateServer::RegisterAll**:  
  
 [!code-cpp[25 NVC_MFCOleContainer](../../mfc/codesnippet/cpp/colelinkingdoc-class_3.cpp)]  
  
 Para obter um exemplo `CWinApp`-derivado da definição de classe e `InitInstance` funcionam, consulte OCLIENT. H e OCLIENT. CPP no exemplo de MFC [OCLIENT](../../visual-cpp-samples.md).  
  
 Para obter mais informações sobre como usar o `COleLinkingDoc`, consulte os artigos [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [contêineres: recursos avançados](../../mfc/containers-advanced-features.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 `COleLinkingDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="colelinkingdoc"></a>COleLinkingDoc::COleLinkingDoc  
 Constrói uma `COleLinkingDoc` objeto sem iniciar comunicações com DLLs do sistema OLE.  
  
```  
COleLinkingDoc();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar o `Register` a função de membro para informar OLE que o documento está aberto.  
  
##  <a name="onfindembeddeditem"></a>COleLinkingDoc::OnFindEmbeddedItem  
 Chamado pela estrutura para determinar se o documento contém um item OLE incorporado com o nome especificado.  
  
```  
virtual COleClientItem* OnFindEmbeddedItem(LPCTSTR lpszItemName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszItemName`  
 Ponteiro para o nome do OLE incorporados item solicitado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o item especificado; **Nulo** se o item não for encontrado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de pesquisa a lista de itens inseridos por um item com o nome especificado (a comparação de nome diferencia maiusculas de minúsculas). Substitua essa função se você tiver seu próprio método de armazenamento ou nomenclatura itens inseridos OLE.  
  
##  <a name="ongetlinkeditem"></a>COleLinkingDoc::OnGetLinkedItem  
 Chamado pela estrutura para verificar se o documento contém um item de servidor vinculado com o nome especificado.  
  
```  
virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszItemName`  
 Ponteiro para o nome da OLE vinculado item solicitado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o item especificado; **Nulo** se o item não for encontrado.  
  
### <a name="remarks"></a>Comentários  
 O padrão `COleLinkingDoc` implementação sempre retorna **nulo**. Essa função é substituído na classe derivada `COleServerDoc` para pesquisar a lista de itens de servidor OLE para um item vinculado com o nome especificado (a comparação de nome diferencia maiusculas de minúsculas). Substitua essa função se você implementou o seu próprio método de armazenar ou recuperar itens do servidor vinculado.  
  
##  <a name="register"></a>COleLinkingDoc::Register  
 Informa a DLLs do sistema OLE que o documento está aberto.  
  
```  
BOOL Register(
    COleObjectFactory* pFactory,  
    LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFactory*  
 Ponteiro para um objeto de fábrica OLE (pode ser **nulo**).  
  
 `lpszPathName`  
 Ponteiro para o caminho totalmente qualificado do documento recipiente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento for registrado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função ao criar ou abrir um arquivo nomeado para registrar o documento com as DLLs do sistema OLE. Não é necessário para chamar essa função se o documento representa um item incorporado.  
  
 Se você estiver usando `COleTemplateServer` em seu aplicativo, `Register` é chamado para você por `COleLinkingDoc`da implementação de `OnNewDocument`, `OnOpenDocument`, e `OnSaveDocument`.  
  
##  <a name="revoke"></a>COleLinkingDoc::Revoke  
 Informa a DLLs do sistema OLE que o documento não estiver aberto.  
  
```  
void Revoke();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para revogar o registro do documento com as DLLs do sistema OLE.  
  
 Você deve chamar essa função ao fechar um arquivo nomeado, mas geralmente não é necessário chamá-lo diretamente. `Revoke`é chamado para você por `COleLinkingDoc`da implementação de `OnCloseDocument`, `OnNewDocument`, `OnOpenDocument`, e `OnSaveDocument`.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)

