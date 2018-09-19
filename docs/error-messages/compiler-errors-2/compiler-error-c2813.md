---
title: Erro do compilador C2813 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- C2813
ms.assetid: 6cf2135f-7b82-42d1-909a-5e864308a09c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b8b7912edeea9edbb32632953166fc2558aeed3e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062651"
---
# <a name="compiler-error-c2813"></a>Erro do compilador C2813

\#importação não é suportada com /MP

C2813 é emitida se em um comando do compilador que você especificar o **/MP** opção de compilador e dois ou mais arquivos a compilação e um ou mais dos arquivos contém o[#import](../../preprocessor/hash-import-directive-cpp.md) diretiva de pré-processador. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva gera classes C++ entre os tipos na biblioteca de tipos especificada e, em seguida, grava essas classes em dois arquivos de cabeçalho. O [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva não tem suporte porque se várias unidades de compilação importar a mesma biblioteca de tipos, essas unidades de conflito ao tentar gravar os mesmos arquivos de cabeçalho ao mesmo tempo.

Este erro do compilador e o **/MP** opção de compilador são novos no Visual Studio 2008.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2813. A linha de comando no "compilar com:" comentário indica ao compilador para usar o **/MP** e **/c** opções do compilador para compilar vários arquivos. Pelo menos um dos arquivos contém o [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva. Podemos usar o mesmo arquivo duas vezes para fins de teste, este exemplo.

```
// C2813.cpp
// compile with: /MP /c C2813.cpp C2813.cpp
#import "C:\windows\system32\stdole2.tlb"   // C2813
int main()
{
}
```