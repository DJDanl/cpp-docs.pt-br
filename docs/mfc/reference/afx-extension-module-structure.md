---
title: Estrutura AFX_EXTENSION_MODULE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- AFX_EXTENSION_MODULE
dev_langs:
- C++
helpviewer_keywords:
- AFX_EXTENSION_MODULE structure [MFC]
ms.assetid: b85a989c-d0c5-4b28-b53c-dad45b75704e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e741f172d0dfe528a166fad087460fd9ae18c0f3
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951176"
---
# <a name="afxextensionmodule-structure"></a>Estrutura AFX_EXTENSION_MODULE
O `AFX_EXTENSION_MODULE` é usado durante a inicialização de DLLs de extensão do MFC para manter o estado do módulo DLL de extensão do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct AFX_EXTENSION_MODULE  
{  
    BOOL bInitialized;  
    HMODULE hModule;  
    HMODULE hResource;  
    CRuntimeClass* pFirstSharedClass;  
    COleObjectFactory* pFirstSharedFactory;  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *bInitialized*  
 **TRUE** se o módulo DLL foi inicializado com `AfxInitExtensionModule`.  
  
 *hModule*  
 Especifica o identificador do módulo DLL.  
  
 *hResource*  
 Especifica o identificador do módulo de recurso personalizado de DLL.  
  
 *pFirstSharedClass*  
 Um ponteiro para informações (o `CRuntimeClass` estrutura) sobre a primeira classe de tempo de execução do módulo DLL. Usado para fornecer o início da lista de classe de tempo de execução.  
  
 *pFirstSharedFactory*  
 Um ponteiro para a fábrica do módulo DLL primeiro (um `COleObjectFactory` objeto). Usado para fornecer o início da lista de fábrica de classe.  
  
## <a name="remarks"></a>Comentários  
 Extensão do MFC DLLs precisa fazer duas coisas em seus `DllMain` função:  
  
-   Chamar [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule) e verifique se o valor de retorno.  
  
-   Criar um `CDynLinkLibrary` objeto se a DLL estiver exportando [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados.  
  
 O `AFX_EXTENSION_MODULE` estrutura é usada para manter uma cópia da extensão do MFC estado do módulo DLL, incluindo uma cópia dos objetos de classe de tempo de execução que foram inicializados pela DLL de extensão do MFC como parte da construção de objeto estático normal executada antes do `DllMain` é inserido. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL#2](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_1.cpp)]  
  
 As informações de módulo armazenadas no `AFX_EXTENSION_MODULE` estrutura pode ser copiada para o `CDynLinkLibrary` objeto. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL#5](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule)   
 [AfxTermExtensionModule](extension-dll-macros.md#afxtermextensionmodule)

