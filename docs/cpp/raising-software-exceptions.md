---
title: Acionando exceções de software
ms.date: 11/04/2016
helpviewer_keywords:
- run-time errors, treating as exceptions
- exception handling [C++], errors as exceptions
- exceptions [C++], flagging errors as exceptions
- errors [C++], treating as exceptions
- exception handling [C++], detecting errors
- structured exception handling [C++], errors as exceptions
- exceptions [C++], software
- RaiseException function
- software exceptions [C++]
- formats [C++], exception codes
ms.assetid: be1376c3-c46a-4f52-ad1d-c2362840746a
ms.openlocfilehash: 7c58ae2e2b6635345a162d11d2b75a9865d37751
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246400"
---
# <a name="raising-software-exceptions"></a>Acionando exceções de software

Algumas das origens mais comuns de erros do programa não são sinalizadas como exceções pelo sistema. Por exemplo, se você tenta alocar um bloco de memória, mas não há memória suficiente, o tempo de execução ou a função de API não geram uma exceção, mas retornam um código de erro.

No entanto, você pode tratar qualquer condição como uma exceção detectando essa condição em seu código e, em seguida, relatando-a chamando a função [RaiseException](/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception) . Ao sinalizar erros dessa maneira, você aproveitas as vantagens de manipulação de exceções estruturada em qualquer tipo de erro de tempo de execução.

Para usar a manipulação de exceção estruturada com erros:

- Defina seu próprio código de exceção para o evento.

- Chame `RaiseException` ao detectar um problema.

- Use filtros de manipulação de exceções para testar o código de exceção definido.

O arquivo \<Winerror. h > mostra o formato dos códigos de exceção. Para verificar se você não definiu um código em conflito com um código de exceção existente, defina o terceiro bit mais significativo como 1. Os quatro bit mais significativos devem ser definidos como mostrado na tabela a seguir.

|Bits|Configuração binária recomendada|Descrição|
|----------|--------------------------------|-----------------|
|31-30|11|Esses dois bits descrevem o status básico de código:  11 = erro, 00 = êxito, 01 = informativo, 10 = aviso.|
|29|1|Bit cliente. Definido como 1 para códigos definidos pelo usuário.|
|28|0|Bit reservado. (Deixe definido como 0.)|

Você pode definir os dois primeiros bits com uma configuração diferente do 11 binário se você desejar, embora a configuração de “erro” seja apropriada para a maioria das exceções. É importante lembrar de definir os bits 29 e 28 conforme mostrado na tabela anterior.

O código de erro resultante, portanto, deve ter os quatro bits mais altos definidos como hexadecimal E. Por exemplo, as definições a seguir definem códigos de exceção que não entram em conflito com nenhum código de exceção do Windows. (No entanto, talvez seja necessário verificar se os códigos são usados por DLL de terceiros.)

```cpp
#define STATUS_INSUFFICIENT_MEM       0xE0000001
#define STATUS_FILE_BAD_FORMAT        0xE0000002
```

Depois que você tiver definido um código de exceção, poderá usá-lo para gerar uma exceção. Por exemplo, o código a seguir gera a exceção `STATUS_INSUFFICIENT_MEM` em resposta a um problema de alocação de memória:

```cpp
lpstr = _malloc( nBufferSize );
if (lpstr == NULL)
    RaiseException( STATUS_INSUFFICIENT_MEM, 0, 0, 0);
```

Se você quiser simplesmente gerar uma exceção, pode definir os últimos três parâmetros como 0. Os últimos três parâmetros são úteis para passar informações adicionais e definir um sinalizador que impeça manipuladores de continuarem a execução. Consulte a função [RaiseException](/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception) no SDK do Windows para obter mais informações.

Em seus filtros de manipulação de exceções, você pode testar os códigos que você definiu. Por exemplo:

```cpp
__try {
    ...
}
__except (GetExceptionCode() == STATUS_INSUFFICIENT_MEM ||
        GetExceptionCode() == STATUS_FILE_BAD_FORMAT )
```

## <a name="see-also"></a>Consulte também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Manipulação de exceção estruturada (C++C/)](../cpp/structured-exception-handling-c-cpp.md)