---
title: Erro do compilador C2813
ms.date: 11/04/2016
helpviewer_keywords:
- C2813
ms.assetid: 6cf2135f-7b82-42d1-909a-5e864308a09c
ms.openlocfilehash: b36e966d897b1a3f9a4f601ef281091160da34c3
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750930"
---
# <a name="compiler-error-c2813"></a>Erro do compilador C2813

Não há suporte para a importação de \#com/MP

C2813 é emitido se estiver em um comando do compilador, você especificar a opção de compilador **/MP** e dois ou mais arquivos a serem compilados, e um ou mais arquivos conterá a diretiva de pré-processador de[#import](../../preprocessor/hash-import-directive-cpp.md) . A diretiva [#import](../../preprocessor/hash-import-directive-cpp.md) gera C++ classes dos tipos na biblioteca de tipos especificada e, em seguida, grava essas classes em dois arquivos de cabeçalho. A diretiva de [#import](../../preprocessor/hash-import-directive-cpp.md) não tem suporte porque, se várias unidades de compilação importarem a mesma biblioteca de tipos, essas unidades entrarão em conflito quando tentarem gravar os mesmos arquivos de cabeçalho ao mesmo tempo.

Esse erro do compilador e a opção de compilador **/MP** são novas no Visual Studio 2008.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2813. A linha de comando no comentário "Compile with:" indica ao compilador para usar as opções de compilador **/MP** e **/c** para compilar vários arquivos. Pelo menos um dos arquivos contém a diretiva [#import](../../preprocessor/hash-import-directive-cpp.md) . Usamos o mesmo arquivo duas vezes para testar este exemplo.

```cpp
// C2813.cpp
// compile with: /MP /c C2813.cpp C2813.cpp
#import "C:\windows\system32\stdole2.tlb"   // C2813
int main()
{
}
```
