---
title: Estrutura AFX_EXTENSION_MODULE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- AFX_EXTENSION_MODULE
dev_langs:
- C++
helpviewer_keywords:
- AFX_EXTENSION_MODULE structure
ms.assetid: b85a989c-d0c5-4b28-b53c-dad45b75704e
caps.latest.revision: 11
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
ms.sourcegitcommit: bb94e24657d16b2a3eda3a770c2b6ae734c6006f
ms.openlocfilehash: 4bc0dafbc4d09f5c53ff502876da2e250d537882
ms.lasthandoff: 04/12/2017

---
# <a name="afxextensionmodule-structure"></a>Estrutura AFX_EXTENSION_MODULE
O `AFX_EXTENSION_MODULE` é usado durante a inicialização de DLLs de extensão do MFC para manter o estado do módulo DLL de extensão.  
  
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
 Extensão do MFC DLLs precisam fazer duas coisas em seus `DllMain` função:  
  
-   Chamar [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule) e verifique se o valor de retorno.  
  
-   Criar um **CDynLinkLibrary** objeto se a DLL estiver exportando [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados.  
  
 O `AFX_EXTENSION_MODULE` estrutura é usada para manter uma cópia da extensão de estado do módulo DLL, incluindo uma cópia dos objetos de classe de tempo de execução que foram inicializados pela extensão DLL como parte da construção de objeto estático normal executada antes do `DllMain` é inserido. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL N º 2](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_1.cpp)]  
  
 As informações de módulo armazenadas no `AFX_EXTENSION_MODULE` estrutura pode ser copiada para o **CDynLinkLibrary** objeto. Por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL N º 5](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule)   
 [AfxTermExtensionModule](extension-dll-macros.md#afxtermextensionmodule)


