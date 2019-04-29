---
title: Estrutura AFX_EXTENSION_MODULE
ms.date: 11/04/2016
f1_keywords:
- AFX_EXTENSION_MODULE
helpviewer_keywords:
- AFX_EXTENSION_MODULE structure [MFC]
ms.assetid: b85a989c-d0c5-4b28-b53c-dad45b75704e
ms.openlocfilehash: e1bdc9d744424ab0ad59be3bd7b815b5122bcd10
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338630"
---
# <a name="afxextensionmodule-structure"></a>Estrutura AFX_EXTENSION_MODULE

O `AFX_EXTENSION_MODULE` é usado durante a inicialização de DLLs de extensão do MFC para manter o estado do módulo de DLL de extensão do MFC.

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

*bInitialized*<br/>
TRUE se o módulo DLL foi inicializado com `AfxInitExtensionModule`.

*hModule*<br/>
Especifica o identificador do módulo DLL.

*hResource*<br/>
Especifica o identificador do módulo de DLL de recurso personalizado.

*pFirstSharedClass*<br/>
Um ponteiro para informações (o `CRuntimeClass` estrutura) sobre a primeira classe de tempo de execução do módulo DLL. Usado para fornecer o início da lista de classe de tempo de execução.

*pFirstSharedFactory*<br/>
Um ponteiro para a primeira fábrica de objeto do módulo DLL (um `COleObjectFactory` objeto). Usado para fornecer o início da lista de classe de fábrica.

## <a name="remarks"></a>Comentários

Extensão MFC DLLs é preciso fazer duas coisas em seus `DllMain` função:

- Chame [AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule) e verifique o valor retornado.

- Criar uma `CDynLinkLibrary` do objeto se a DLL estiver exportando [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objetos ou tem seus próprios recursos personalizados.

O `AFX_EXTENSION_MODULE` estrutura é usada para manter uma cópia do estado do módulo DLL, incluindo uma cópia dos objetos de classe de tempo de execução que foram inicializados pela DLL de extensão de MFC como parte da construção de objeto estático normal executada antes de extensão do MFC `DllMain` é inserido. Por exemplo:

[!code-cpp[NVC_MFC_DLL#2](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_1.cpp)]

As informações de módulo armazenadas em do `AFX_EXTENSION_MODULE` estrutura pode ser copiada para o `CDynLinkLibrary` objeto. Por exemplo:

[!code-cpp[NVC_MFC_DLL#5](../../atl-mfc-shared/codesnippet/cpp/afx-extension-module-structure_2.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[AfxInitExtensionModule](extension-dll-macros.md#afxinitextensionmodule)<br/>
[AfxTermExtensionModule](extension-dll-macros.md#afxtermextensionmodule)
