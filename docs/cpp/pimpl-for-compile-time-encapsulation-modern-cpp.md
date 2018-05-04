---
title: Pimpl para encapsulamento do tempo de compilação (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c3e8a90a-b328-4990-82bb-e1b147f76e07
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f611a898018cee5edc031be1db2fd35af8857e16
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="pimpl-for-compile-time-encapsulation-modern-c"></a>Pimpl para encapsulamento do tempo de compilação (C++ moderno)
O *pimpl idioma* é uma técnica de C++ moderna para ocultar a implementação, para minimizar o acoplamento e separe interfaces. Pimpl é abreviação de "o ponteiro para implementação." Você pode já estar familiarizado com o conceito, mas sabe por outros nomes como idioma gato Cheshire ou Firewall do compilador.  
  
## <a name="why-use-pimpl"></a>Por que usar pimpl?  
 Aqui está como o idioma pimpl pode melhorar o ciclo de vida de desenvolvimento de software:  
  
-   Minimização de dependências de compilação.  
  
-   Separação de interface e implementação.  
  
-   Portabilidade.  
  
## <a name="pimpl-header"></a>Cabeçalho Pimpl  
  
```cpp  
// my_class.h  
class my_class {  
   //  ... all public and protected stuff goes here ...  
private:  
   class impl; unique_ptr<impl> pimpl; // opaque type here  
};  
  
```  
  
 O idioma pimpl evita cascatas de recriação e layouts de objeto frágil. Ele é adequado para tipos conhecidos (transitivamente).  
  
## <a name="pimpl-implementation"></a>Implementação de Pimpl  
 Definir o `impl` classe no arquivo. cpp.  
  
```cpp  
// my_class.cpp  
class my_class::impl {  // defined privately here  
  // ... all private data and functions: all of these  
  //     can now change without recompiling callers ...  
};  
my_class::my_class(): pimpl( new impl )  
{  
  // ... set impl values ...   
}  
```  
  
## <a name="best-practices"></a>Práticas recomendadas  
 Considere a possibilidade de adicionar suporte para não gerar especialização de troca.  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)