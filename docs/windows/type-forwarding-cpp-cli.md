---
title: Encaminhamento de tipos (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- type forwarding, Visual C++
ms.assetid: ae730b69-0c27-41cc-84e1-3132783866ea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9caa2e18a1ec851967857eb068797e092835f587
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891082"
---
# <a name="type-forwarding-ccli"></a>Encaminhamento de tipos (C++/CLI)
*Encaminhamento de tipos* permite que você mova um tipo de um assembly (um assembly) em outro assembly (assembly B), de modo que não é necessário recompilar os clientes que utilizam o assembly A.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 Não há suporte para esse recurso em todos os tempos de execução.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Não há suporte para esse recurso no Windows Runtime.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 O exemplo de código a seguir demonstra como usar o encaminhamento de tipo.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
#using "new.dll"  
[assembly:TypeForwardedTo(type::typeid)];  
```  
  
### <a name="parameters"></a>Parâmetros  
 `new`  
 O assembly no qual você está movendo a definição de tipo.  
  
 `type`  
 O tipo cuja definição que você está movendo em outro assembly.  
  
### <a name="remarks"></a>Comentários  
 Depois que um componente (assembly) fornecido e está sendo usado por aplicativos cliente, você pode usar encaminhamento para mover um tipo de componente (assembly) em outro assembly, enviar o componente atualizado (e todos os assemblies adicionais necessárias) de tipo e o cliente aplicativos ainda funcionarão sem ser recompilada.  
  
 Encaminhamento de tipo só funciona para componentes referenciados pelos aplicativos existentes. Quando você recria um aplicativo, deve haver as referências a assembly apropriadas para quaisquer tipos usados no aplicativo.  
  
 Quando o encaminhamento de um tipo (A) de um assembly, você deve adicionar o `TypeForwardedTo` atributo de tipo, bem como uma referência de assembly. O assembly referenciado deve conter um dos seguintes:  
  
-   A definição para a tipo.  
  
-   Um `TypeForwardedTo` atributo para um tipo, bem como uma referência de assembly.  
  
 Exemplos de tipos que possam ser encaminhados incluem:  
  
-   classes de referência  
  
-   classes de valor  
  
-   enums  
  
-   interfaces  
  
 Você não pode encaminhar os seguintes tipos:  
  
-   Tipos genéricos  
  
-   Tipos nativos  
  
-   Tipos aninhados (se você quiser encaminhar um tipo aninhado, encaminhe o tipo de delimitador)  
  
 Você pode encaminhar um tipo para um assembly criado em qualquer linguagem direcionar o common language runtime.  
  
 Portanto, se um arquivo de código fonte que é usado para compilar o assembly. dll contém uma definição de tipo (`ref class MyClass`), e você deseja mover esse tipo de definição para o assembly b. dll, você deve:  
  
1.  Mover o `MyClass` definição para um arquivo de código de origem usado para criar o b. dll de tipo.  
  
2.  Compile o assembly b. dll  
  
3.  Excluir o `MyClass` tipo de definição do código-fonte usada para criar o. dll e substituí-lo com o seguinte:  
  
    ```  
    #using "B.dll"  
    [assembly:TypeForwardedTo(MyClass::typeid)];  
    ```  
  
4.  Compile o assembly. dll.  
  
5.  Use o. dll sem recompilar os aplicativos cliente.  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**