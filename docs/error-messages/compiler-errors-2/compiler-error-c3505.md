---
title: Erro do compilador C3505
ms.date: 11/04/2016
f1_keywords:
- C3505
helpviewer_keywords:
- C3505
ms.assetid: ed73c99e-93a1-4f3a-bac7-ba7ed5d836e4
ms.openlocfilehash: 5730102371d00ebaf3ae05fdefb70184b58d7c18
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400325"
---
# <a name="compiler-error-c3505"></a>Erro do compilador C3505

> não é possível carregar a biblioteca de tipos '*guid*'

C3505 pode ser causado se você estiver executando o 32 bits, hospedados em x86 compilador cruzado de 64 bits, x64 destinos em 64 bits da máquina, porque o compilador está em execução no WOW64 e só podem ler o hive do registro de 32 bits.

Você pode resolver esse erro, criando versões de 32 bits e 64 bits da biblioteca de tipos que você está tentando importar e, em seguida, registre-os.  Ou você pode usar o compilador nativo de 64 bits, que exige que você altere seu **diretórios VC + +** propriedade no IDE para apontar para o compilador de 64 bits.

Para obter mais informações, consulte

- [Como: Habilitar um conjunto de ferramentas Visual C++ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)

- [Como: Configurar projetos do Visual C++ para terem plataformas x64 de 64 bits como destino](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)