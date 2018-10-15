---
title: Tratamento de exceções (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- structured exception handling [C++], managed exceptions
- Exception class, managed applications
- exception handling
- C++ exception handling
- exception handling, types of
- System::Exception class in managed applications
ms.assetid: ccb11fe8-6938-41ac-b477-a183e85865b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7d070cc223f90f84bd52176ee7e50dbbfa441789
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328123"
---
# <a name="exception-handling--ccli-and-ccx"></a>Tratamento de exceções (C + + c++ /CLI e c++ /CLI CX)

Aplicativos compilados com o `/ZW` opção de compilador ou `/clr` opção de compilador ambos usam *exceções* para lidar com erros inesperados durante a execução do programa. Os tópicos a seguir discutem o tratamento de exceções em qualquer um dos C + + c++ /CLI CX ou C + + c++ /CLI aplicativos CLI.

## <a name="in-this-section"></a>Nesta seção

[Conceitos básicos do uso de exceções gerenciadas](../dotnet/basic-concepts-in-using-managed-exceptions.md)<br/>
Descreve Lançando exceções e usando **tente**/**catch** blocos.

[Diferenças na exceção comportamento de tratamento em /clr](../dotnet/differences-in-exception-handling-behavior-under-clr.md)<br/>
Discute as diferenças do comportamento padrão de tratamento de exceções C++.

[finally](../dotnet/finally.md)<br/>
Discute como usar a palavra-chave finally.

[Como definir e instalar um manipulador de exceção global](../dotnet/how-to-define-and-install-a-global-exception-handler.md)<br/>
Demonstra como sem tratamento de exceções podem ser capturadas.

[Como capturar exceções em código nativo lançadas pela MSIL](../dotnet/how-to-catch-exceptions-in-native-code-thrown-from-msil.md)<br/>
Discute como capturar exceções de CLR e C++ em código nativo.

[Como definir e instalar um manipulador de exceção global](../dotnet/how-to-define-and-install-a-global-exception-handler.md)<br/>
Demonstra como capturar exceções não tratadas.

## <a name="related-sections"></a>Seções relacionadas

[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)<br/>
Descreve o tratamento de exceções em C++ padrão.

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)