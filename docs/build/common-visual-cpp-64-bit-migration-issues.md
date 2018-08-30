---
title: Problemas comuns na migração de 64 bits do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- 64-bit programming [C++], migration
- 64-bit compiler [C++], migration
- porting 32-bit code to 64-bit code
- upgrading Visual C++ applications, 32-bit code
- migration [C++], 64-bit code issues
- 32-bit code porting [C++]
- 64-bit applications [C++]
- 64-bit compiler [C++], porting 32-bit code
- Win64 [C++]
ms.assetid: d17fb838-7513-4e2d-8b27-a1666f17ad76
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fadc3d48eb6ba812415cbedc9c077e7ffc1b4016
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43208152"
---
# <a name="common-visual-c-64-bit-migration-issues"></a>Problemas de migração de 64 bits do Visual C++comuns

Quando você usa o Visual C++ para criar aplicativos para execução em um sistema de operacional do Windows de 64 bits, você deve estar ciente dos seguintes problemas:  
  
-   Uma `int` e um `long` são valores de 32 bits em sistemas de operacionais do Windows de 64 bits. Por programas que você pretende compilar para plataformas de 64 bits, você deve ter cuidado para não atribuir ponteiros para variáveis de 32 bits. Os ponteiros são 64 bits em plataformas de 64 bits e você irá truncar o valor do ponteiro, se ela for atribuída a uma variável de 32 bits.  
  
-   `size_t`, `time_t`, e `ptrdiff_t` são valores de 64 bits em sistemas de operacionais do Windows de 64 bits.  
  
-   `time_t` é um valor de 32 bits em sistemas de operacionais Windows 32 bits em versões do Visual C++ antes do Visual C++ 2005. `time_t` Agora é um inteiro de 64 bits por padrão. Para obter mais informações, consulte [gerenciamento de tempo](../c-runtime-library/time-management.md).  
  
     Você deve estar ciente de onde seu código usa um `int` de valor e processa-o como uma `size_t` ou `time_t` valor. É possível que o número pode aumentar para ser maior do que um número de 32 bits e os dados serão truncados quando ele é passado de volta para o `int` armazenamento.  
  
O %x (hexadecimal `int` formato) `printf` modificador não funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits. Ele só funciona nos primeiros 32 bits do valor que é passado para ele.  
  
-   Use % I32x para exibir um tipo integral de 32 bits em formato hexadecimal.  
  
-   Use % I64x para exibir um tipo integral de 64 bits em formato hexadecimal.  
  
-   O %p (formato hexadecimal para um ponteiro) funcionará conforme o esperado em um sistema de operacional do Windows de 64 bits.  
  
Para obter mais informações, consulte:  
  
-   [Opções do Compilador](../build/reference/compiler-options.md)  
  
-   [Dicas de migração](/windows/desktop/WinProg64/migration-tips)  
  
## <a name="see-also"></a>Consulte também  

[Configurar o Visual C++ para x64 de 64 bits, destinos](../build/configuring-programs-for-64-bit-visual-cpp.md)   
[Guia de atualização e portabilidade do Visual C++](../porting/visual-cpp-porting-and-upgrading-guide.md)