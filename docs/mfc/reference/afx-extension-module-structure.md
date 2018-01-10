---
title: Estrutura AFX_EXTENSION_MODULE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: AFX_EXTENSION_MODULE
dev_langs: C++
helpviewer_keywords: AFX_EXTENSION_MODULE structure [MFC]
ms.assetid: b85a989c-d0c5-4b28-b53c-dad45b75704e
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b4ac896fb16aa3c338cadd6273e226eebe986ae7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
 `hModule`  
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
  
-   Criar um **CDynLinkLibrary** objeto se a DLL estiver exportando [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados.  
  
 O `AFX_EXTENSION_MODULE` estrutura é usada para manter uma cópia da extensão do MFC estado do módulo DLL, incluindo uma cópia dos objetos de classe de tempo de execução que foram inicializados pela DLL de extensão do MFC como parte da construção de objeto estático normal executada antes do `DllMain` é inserido. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL#2](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_1.cpp)]  
  
 As informações de módulo armazenadas no `AFX_EXTENSION_MODULE` estrutura pode ser copiada para o **CDynLinkLibrary** objeto. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL#5](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule)   
 [AfxTermExtensionModule](extension-dll-macros.md#afxtermextensionmodule)

