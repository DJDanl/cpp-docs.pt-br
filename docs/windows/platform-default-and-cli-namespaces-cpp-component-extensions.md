---
title: Plataforma padrão, Namespaces e cli (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- lang
- cli
dev_langs:
- C++
helpviewer_keywords:
- lang namespace
- cli namespace
ms.assetid: 9d38bd1e-dc78-47d1-a84b-9b4683e52c9c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c63ce7dc5dcd326de426c4e4738a11e24f93161c
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40015527"
---
# <a name="platform-default-and-cli-namespaces--c-component-extensions"></a>Namespaces Plataforma, padrão e cli (Extensões de Componentes C++)
Um namespace qualifica os nomes dos elementos da linguagem para que os nomes não entrem em conflito com nomes idênticos em outras áreas do código-fonte. Por exemplo, uma colisão de nomes pode impedir o compilador reconhecer [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md). Os namespaces são usados pelo compilador, mas não preservados no assembly compilado.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 O Visual C++ fornece um namespace padrão para seu projeto quando o projeto é criado. Você pode renomear manualmente o namespace, embora no tempo de execução do Windows, o nome do arquivo. winmd deve corresponder ao nome do namespace raiz.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Para obter mais informações, consulte [Namespaces e visibilidade de tipos (C + + c++ /CX)](http://msdn.microsoft.com/library/windows/apps/hh969551.aspx).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/ZW`  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
### <a name="syntax"></a>Sintaxe  
  
```cpp  
using namespace cli;  
```  
  
### <a name="remarks"></a>Comentários  
  
 O C + + c++ CLI é compatível com o **cli** namespace. Ao compilar com `/clr`, o **usando** instrução na seção de sintaxe é implícita.  
  
 Os seguintes recursos de linguagem estão na **cli** namespace:  
  
-   [Matrizes](../windows/arrays-cpp-component-extensions.md)  
  
-   [interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)  
  
-   [pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)  
  
-   [Safe_cast](../windows/safe-cast-cpp-component-extensions.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
### <a name="examples"></a>Exemplos  
  
 O exemplo de código a seguir demonstra o que é possível usar um símbolo na **cli** namespace como um símbolo definido pelo usuário em seu código.  No entanto, depois de você ter feito isso, você terá qualificar explícita ou implicitamente suas referências para o **cli** elemento de linguagem do mesmo nome.  
  
```cpp  
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