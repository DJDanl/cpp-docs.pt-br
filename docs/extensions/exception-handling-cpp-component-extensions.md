---
title: Tratamento de exceções (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- structured exception handling [C++], managed exceptions
- Exception class, managed applications
- exception handling
- C++ exception handling
- exception handling, types of
- System::Exception class in managed applications
ms.assetid: ccb11fe8-6938-41ac-b477-a183e85865b9
ms.openlocfilehash: 9f5662bb9e744b5db3b0ab25ac4230b2f67016bd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182117"
---
# <a name="exception-handling--ccli-and-ccx"></a>Tratamento de exceções (C++/CLI e C++/CX)

Os aplicativos compilados com a opção de compilador `/ZW` ou `/clr` usam as *exceptions* para lidar com erros inesperados durante a execução do programa. Os tópicos a seguir discutem o tratamento de exceções em aplicativos C++/CLI ou C++/CX.

## <a name="in-this-section"></a>Nesta seção

[Conceitos básicos do uso de exceções gerenciadas](../dotnet/basic-concepts-in-using-managed-exceptions.md)<br/>
Descreve como lançar exceções e usar os blocos **try**/**catch**.

[Diferenças no comportamento do tratamento de exceções em /clr](../dotnet/differences-in-exception-handling-behavior-under-clr.md)<br/>
Discute as diferenças do comportamento padrão do tratamento de exceções C++.

[finally](../dotnet/finally.md)<br/>
Discute como usar a palavra-chave finally.

[Como definir e instalar um manipulador de exceção global](../dotnet/how-to-define-and-install-a-global-exception-handler.md)<br/>
Demonstra como capturar as exceções sem tratamento.

[Como capturar exceções em código nativo lançadas pela MSIL](../dotnet/how-to-catch-exceptions-in-native-code-thrown-from-msil.md)<br/>
Discute como capturar exceções de CLR e C++ em código nativo.

[Como definir e instalar um manipulador de exceção global](../dotnet/how-to-define-and-install-a-global-exception-handler.md)<br/>
Demonstra como capturar todas as exceções sem tratamento.

## <a name="related-sections"></a>Seções relacionadas

[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)<br/>
Descreve o tratamento de exceções no C++ padrão.

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
