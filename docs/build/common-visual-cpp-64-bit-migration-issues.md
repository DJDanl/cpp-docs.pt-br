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
ms.openlocfilehash: 004fe7ace6102feecbcb2f542b5b93268ae2f868
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493320"
---
# <a name="common-visual-c-64-bit-migration-issues"></a>Problemas de migração de 64 bits do Visual C++comuns

Ao usar o compilador do Microsoft C++ (MSVC) para criar aplicativos para execução em um sistema operacional Windows de 64 bits, você deve estar ciente dos seguintes problemas:

- Um `int` e um `long` são valores de 32 bits em sistemas operacionais Windows de 64 bits. Para programas que você planeja Compilar para plataformas de 64 bits, você deve ter cuidado para não atribuir ponteiros a variáveis de 32 bits. Os ponteiros são 64 bits em plataformas de 64 bits e você truncará o valor do ponteiro se atribuí-lo a uma variável de 32 bits.

- `size_t`, `time_t`e `ptrdiff_t` são valores de 64 bits em sistemas operacionais Windows de 64 bits.

- `time_t`é um valor de 32 bits em sistemas operacionais Windows de 32 bits no Visual Studio 2005 e versões anteriores. `time_t`Agora é um inteiro de 64 bits por padrão. Para obter mais informações, consulte [Gerenciamento de tempo](../c-runtime-library/time-management.md).

   Você deve estar ciente de onde seu código recebe um `int` valor e o processa como um `size_t` valor `time_t` ou. É possível que o número possa aumentar para ser maior que um número de 32 bits e os dados serão truncados quando forem passados de volta para o `int` armazenamento.

O modificador% x `int` (formato `printf` Hex) não funcionará conforme o esperado em um sistema operacional Windows de 64 bits. Ele funcionará apenas nos primeiros 32 bits do valor que é passado para ele.

- Use% I32x para exibir um tipo integral de 32 bits no formato Hex.

- Use% I64x para exibir um tipo integral de 64 bits no formato Hex.

- O% p (formato hex para um ponteiro) funcionará conforme o esperado em um sistema operacional Windows de 64 bits.

Para obter mais informações, consulte:

- [Opções do compilador MSVC](reference/compiler-options.md)

- [Dicas de migração](/windows/win32/WinProg64/migration-tips)

## <a name="see-also"></a>Confira também

[Configurar projetos C++ para destinos x64 de 64 bits](configuring-programs-for-64-bit-visual-cpp.md)<br/>
[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)
