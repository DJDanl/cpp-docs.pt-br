---
title: Tratamento de exceção (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 2213266d281933c6a6a59775584532acaeb39d6e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412309"
---
# <a name="exception-handling--c-component-extensions"></a>Tratamento de Exceção (Extensões de Componentes C++)

Aplicativos compilados com o `/ZW` opção de compilador ou `/clr` opção de compilador ambos usam *exceções* para lidar com erros inesperados durante a execução do programa. Os tópicos a seguir discutem o tratamento de exceções em qualquer um dos C + + c++ /CLI CX ou C + + c++ /CLI aplicativos CLI.

## <a name="in-this-section"></a>Nesta seção

[Conceitos básicos do uso de exceções gerenciadas](../dotnet/basic-concepts-in-using-managed-exceptions.md)<br/>
Descreve Lançando exceções e usando **tente**/**catch** blocos.

[Diferenças no comportamento em /CLR de tratamento de exceções](../dotnet/differences-in-exception-handling-behavior-under-clr.md)<br/>
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
Descreve o tratamento de exceções em C++.

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)