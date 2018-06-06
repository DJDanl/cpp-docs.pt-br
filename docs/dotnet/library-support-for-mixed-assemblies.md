---
title: Suporte de biblioteca para Assemblies mistos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- msvcm90[d].dll
- mixed assemblies [C++], library support
- msvcmrt[d].lib
- libraries [C++], mixed assemblies
ms.assetid: 1229595c-9e9d-414d-b018-b4e4c727576d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: d4b584e0bacb1cb93cad33efdff807bb5fa9c8e2
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704105"
---
# <a name="library-support-for-mixed-assemblies"></a>Suporte de biblioteca para assemblies mistos

Visual C++ oferece suporte ao uso da biblioteca padrão C++, a biblioteca de tempo de execução do C (CRT), ATL e MFC para aplicativos compilados com [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md). Isso permite que os aplicativos existentes que usam essas bibliotecas para usar recursos do .NET Framework também.

> [!IMPORTANT]
> O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Esse suporte inclui as seguintes bibliotecas de importação e DLL:

- . Lib de Msvcmrt [d] se você compilar com **/clr**. Assemblies mistos o link para a biblioteca de importação.

Esse suporte fornece que vários benefícios relacionados ao:

- A biblioteca padrão C++ e CRT estão disponíveis para código misto. O CRT e biblioteca padrão do C++ fornecidas não são verificáveis; Por fim, as chamadas ainda são roteadas para o mesmo CRT e biblioteca padrão C++ como você está usando no código nativo.

- Corrija o tratamento de exceção unificada nas imagens mistos.

- Inicialização estática de variáveis de C++ em imagens mistas.

- Suporte para variáveis per-AppDomain e por processo no código gerenciado.

- Resolve os problemas de bloqueio do carregador aplicado a mistos DLLs compiladas no Visual Studio 2003 e versões anteriores.

Além disso, esse suporte apresenta as seguintes limitações:

- O modelo de DLL do CRT é suportado para o código compilado com **/clr**. Não há nenhum bibliotecas CRT estáticas que oferecem suporte a **/clr** cria.

Você deve atualizar o tempo de execução de linguagem comum (CLR) para a versão atual que não é garantido que ele funciona com versões anteriores. Criado com essas alterações de código não será executado na versão do CLR 1. x.

## <a name="see-also"></a>Consulte também

- [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
