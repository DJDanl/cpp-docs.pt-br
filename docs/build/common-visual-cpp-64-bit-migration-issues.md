---
title: Problemas de migração de 64 bits do Visual C++comuns
ms.date: 05/06/2019
helpviewer_keywords:
- 64-bit programming [C++], migration
- 64-bit compiler [C++], migration
- porting 32-bit code to 64-bit code
- migration [C++], 64-bit code issues
- 32-bit code porting [C++]
- 64-bit applications [C++]
- 64-bit compiler [C++], porting 32-bit code
- Win64 [C++]
ms.assetid: d17fb838-7513-4e2d-8b27-a1666f17ad76
ms.openlocfilehash: b03ccc76163d79688a98ec89df241292e3eef112
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220878"
---
# <a name="common-visual-c-64-bit-migration-issues"></a>Problemas de migração de 64 bits do Visual C++comuns

Quando você usa o Microsoft C++ (MSVC) para criar aplicativos para execução em um sistema de operacional do Windows de 64 bits do compilador, você deve conhecer os problemas a seguir:

- Uma `int` e um `long` são valores de 32 bits em sistemas de operacionais do Windows de 64 bits. Por programas que você pretende compilar para plataformas de 64 bits, você deve ter cuidado para não atribuir ponteiros para variáveis de 32 bits. Os ponteiros são 64 bits em plataformas de 64 bits e você irá truncar o valor do ponteiro, se ela for atribuída a uma variável de 32 bits.

- `size_t`, `time_t`, e `ptrdiff_t` são valores de 64 bits em sistemas de operacionais do Windows de 64 bits.

- `time_t` é um valor de 32 bits em sistemas de operacionais para Windows de 32 bits no Visual Studio 2005 e versões anteriores. `time_t` Agora é um inteiro de 64 bits por padrão. Para obter mais informações, consulte [gerenciamento de tempo](../c-runtime-library/time-management.md).

   Você deve estar ciente de onde seu código usa um `int` de valor e processa-o como uma `size_t` ou `time_t` valor. É possível que o número pode aumentar para ser maior do que um número de 32 bits e os dados serão truncados quando ele é passado de volta para o `int` armazenamento.

O %x (hexadecimal `int` formato) `printf` modificador não funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits. Ele só funciona nos primeiros 32 bits do valor que é passado para ele.

- Use % I32x para exibir um tipo integral de 32 bits em formato hexadecimal.

- Use % I64x para exibir um tipo integral de 64 bits em formato hexadecimal.

- O %p (formato hexadecimal para um ponteiro) funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits.

Para obter mais informações, consulte:

- [Opções do compilador MSVC](reference/compiler-options.md)

- [Dicas de migração](/windows/desktop/WinProg64/migration-tips)

## <a name="see-also"></a>Consulte também

[Configurar projetos do C++ para x64 de 64 bits, destinos](configuring-programs-for-64-bit-visual-cpp.md)<br/>
[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)
