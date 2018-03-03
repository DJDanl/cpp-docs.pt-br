---
title: Identifier (c + + CLI) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __identifier
- __identifier_cpp
dev_langs:
- C++
helpviewer_keywords:
- __identifier keyword [C++]
ms.assetid: 348428af-afa7-4ff3-b571-acf874301cf2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4d68d21fc9436bff0e39fa474b97ec54138e15b7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="identifier-ccli"></a>__identifier (C++/CLI)
Habilita o uso de palavras-chave do Visual C++ como identificadores.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
**Sintaxe**  
  
```  
__identifier(  
Visual_C++_keyword  
)  
  
```  
  
**Comentários**  
  
Usar o `__identifier` palavra-chave para identificadores que não são palavras-chave é permitida, mas altamente recomendado como uma questão de estilo.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 No exemplo a seguir, uma classe chamada `template` é criado em c# e distribuídos como uma DLL. No programa de Visual C++ que usa o `template` classe, o `__identifier` palavra-chave oculta o fato de que `template` é uma palavra-chave C++ padrão.  
  
```  
// identifier_template.cs  
// compile with: /target:library  
public class template {  
   public void Run() { }  
}  
```  
  
```  
// keyword__identifier.cpp  
// compile with: /ZW  
#using <identifier_template.dll>  
int main() {  
   __identifier(template)^ pTemplate = ref new __identifier(template)();  
   pTemplate->Run();  
}  
```  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Comentários**  
  
 O `__identifier` palavra-chave é válido com o **/clr** opção de compilador.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 No exemplo a seguir, uma classe chamada `template` é criado em c# e distribuídos como uma DLL. No programa de Visual C++ que usa o `template` classe, o `__identifier` palavra-chave oculta o fato de que `template` é uma palavra-chave C++ padrão.  
  
```  
// identifier_template.cs  
// compile with: /target:library  
public class template {  
   public void Run() { }  
}  
```  
  
```  
// keyword__identifier.cpp  
// compile with: /clr  
#using <identifier_template.dll>  
  
int main() {  
   __identifier(template) ^pTemplate = gcnew __identifier(template)();  
   pTemplate->Run();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)   
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)