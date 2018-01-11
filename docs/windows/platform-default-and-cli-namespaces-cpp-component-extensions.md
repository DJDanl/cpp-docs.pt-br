---
title: "Plataforma, padrão e cli Namespaces (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- lang
- cli
dev_langs: C++
helpviewer_keywords:
- lang namespace
- cli namespace
ms.assetid: 9d38bd1e-dc78-47d1-a84b-9b4683e52c9c
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e5fa26b46a110fd59f7568a9101270766928f89
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="platform-default-and-cli-namespaces--c-component-extensions"></a>Namespaces Plataforma, padrão e cli (Extensões de Componentes C++)
Um namespace qualifica os nomes dos elementos da linguagem para que os nomes não entrem em conflito com nomes idênticos em outras áreas do código-fonte. Por exemplo, uma colisão de nomes pode impedir que o compilador reconhecer [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md). Os namespaces são usados pelo compilador, mas não preservados no assembly compilado.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 O Visual C++ fornece um namespace padrão para seu projeto quando o projeto é criado. Você pode renomear manualmente o namespace, embora em tempo de execução do Windows, o nome do arquivo. winmd deve corresponder ao nome do namespace raiz.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Para obter mais informações, consulte [espaços para nome e tipo de visibilidade (C + + CX)](http://msdn.microsoft.com/library/windows/apps/hh969551.aspx).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Sintaxe**  
  
```  
using namespace cli;  
```  
  
 **Comentários**  
  
 C + + CLI oferece suporte a `cli` namespace. Ao compilar com **/clr**, o `using` instrução na seção de sintaxe é inferida.  
  
 Os seguintes recursos de linguagem estão no namespace `cli`:  
  
-   [Matrizes](../windows/arrays-cpp-component-extensions.md)  
  
-   [interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)  
  
-   [pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)  
  
-   [Safe_cast](../windows/safe-cast-cpp-component-extensions.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra que é possível usar um símbolo no namespace `cli` como um símbolo definido pelo usuário em seu código.  No entanto, assim que tiver feito isso, você terá que qualificar explícita ou implicitamente suas referências para o elemento de linguagem `cli` de mesmo nome.  
  
```  
// cli_namespace.cpp  
// compile with: /clr  
using namespace cli;  
int main() {  
   array<int> ^ MyArray = gcnew array<int>(100);  
   int array = 0;  
  
   array<int> ^ MyArray2 = gcnew array<int>(100);   // C2062  
  
   // OK  
   cli::array<int> ^ MyArray2 = gcnew cli::array<int>(100);  
   ::array<int> ^ MyArray3 = gcnew ::array<int>(100);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)