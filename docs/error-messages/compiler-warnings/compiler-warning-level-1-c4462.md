---
title: "Compilador aviso (nível 1) C4462 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4462
dev_langs:
- C++
helpviewer_keywords:
- C4462
ms.assetid: 4e20aca4-293e-4c75-a83d-961c27ab7840
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c6d1e8a698b8201eaaa328963feb69ff07fda2c4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4462"></a>Aviso do compilador (nível 1) C4462
Não é possível determinar o GUID do tipo. O programa poderá falhar no tempo de execução.  
  
 O aviso C4462 ocorre em um aplicativo ou um componente do Tempo de Execução do Windows quando um `TypedEventHandler` público tem como um de seus parâmetros de tipo uma referência para a classe do delimitador.  
  
 **Esse tipo de código gera o aviso:**  
  
```  
namespace N  
{  
       public ref struct EventArgs sealed {};  
       public ref struct R sealed  
       {  
              R() {}  
              event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
       };  
}  
  
[Platform::MTAThread]  
int main()  
{  
     auto x = ref new N::R();  
}  
  
```  
  
 **Para corrigir o erro:**  
  
 Existem duas maneiras de resolver o erro. Uma maneira, mostrada no exemplo a seguir, é dar ao evento a acessibilidade interna para que ele esteja disponível para codificar no mesmo executável, mas não para codificar em outros componentes do Tempo de Execução do Windows.  
  
```  
  
      internal:  
event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
  
```  
  
 Se o evento deve ser público, você pode usar outra solução alternativa, que é expor o evento por meio de uma interface padrão:  
  
```  
  
ref struct R;  
public interface struct IR{ event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;};  
  
public ref struct R sealed : [Windows::Foundation::Metadata::Default] IR  
{  
    R() {}  
    virtual event Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^ e;  
};  
  
```  
  
 O GUID do tipo `Windows::Foundation::TypedEventHandler<R ^, EventArgs^>^` só é usado quando o tipo é acessado de outro componente. A primeira solução alternativa funciona porque só pode ser acessada em seu próprio componente após a solução. Caso contrário, o compilador precisa presumir o pior caso e emitir o aviso.
