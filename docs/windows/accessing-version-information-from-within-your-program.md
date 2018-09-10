---
title: Acessando informações de versão do programa (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.version
dev_langs:
- C++
helpviewer_keywords:
- VerQueryValue
- version information, accessing from within programs
- GetFileVersionInfo
- version information
ms.assetid: 18622333-d9e8-4309-9465-677cd10c79b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b9340ffc4e951a08b77ce44afd6666d8b3a94db9
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315256"
---
# <a name="accessing-version-information-from-within-your-program-c"></a>Acessando informações de versão do programa (C++)

### <a name="to-access-version-information-from-within-your-program"></a>Para acessar informações de versão do seu programa

1. Se você quiser acessar as informações de versão do seu programa, use o [GetFileVersionInfo](/windows/desktop/api/winver/nf-winver-getfileversioninfoa) função e o [VerQueryValue](/windows/desktop/api/winver/nf-winver-verqueryvaluea) função.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de informações de versão](../windows/version-information-editor.md)  
[Informações de versão (Windows)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)