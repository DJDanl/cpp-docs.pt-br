---
title: 'Como: instanciar componentes WRL diretamente | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 1a9fa011-0cee-4abf-bf83-49adf53ff906
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 127a8430e79e7963ea94646f70179df2f30450ff
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878802"
---
# <a name="how-to-instantiate-wrl-components-directly"></a>Como instanciar componentes WRL diretamente
Saiba como usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++[Microsoft::WRL::Make](../windows/make-function.md) e [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md) funções para criar uma instância de um componente do módulo que Define a ele.  
  
 Instanciando componentes diretamente, você pode reduzir a sobrecarga quando você não precisa fábricas de classe ou outros mecanismos. Você pode instanciar um componente diretamente em ambos os aplicativos de plataforma Universal do Windows e em aplicativos de área de trabalho.  
  
Para saber como usar a biblioteca de modelos C++ do Windows Runtime para criar um componente COM clássico e criar uma instância de um aplicativo externo de área de trabalho, consulte [como: criar um componente COM clássico](../windows/how-to-create-a-classic-com-component-using-wrl.md).  
  
 Este documento mostra dois exemplos. O primeiro exemplo usa o `Make` função para criar uma instância de um componente. O segundo exemplo usa o `MakeAndInitialize` função para criar uma instância de um componente que pode falhar durante a construção. (Como COM normalmente usa `HRESULT` valores, em vez de exceções para indicar erros, um tipo COM normalmente não lançar de seu construtor. `MakeAndInitialize` permite que um componente validar seus argumentos de construção por meio de `RuntimeClassInitialize` método.) Os dois exemplos definem uma interface de agente de log básica e implementam essa interface definindo uma classe que grava mensagens no console.  
  
> [!IMPORTANT]
>  Não é possível usar o `new` operador para instanciar os componentes da biblioteca de modelos C++ do Windows Runtime. Portanto, é recomendável que você sempre use `Make` ou `MakeAndInitialize` para criar uma instância de um componente diretamente.  
  
### <a name="to-create-and-instantiate-a-basic-logger-component"></a>Para criar e instanciar um componente básico do agente de log  
  
1.  No Visual Studio, crie um **aplicativo do Console Win32** projeto. Nome do projeto, por exemplo, `WRLLogger`.  
  
2.  Adicionar um **arquivo Midl (. idl)** arquivo ao projeto, nomeie o arquivo `ILogger.idl`e, em seguida, adicione este código:  
  
     [!code-cpp[wrl-logger-make#1](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_1.idl)]  
  
3.  Use o código a seguir para substituir o conteúdo de WRLLogger.cpp.  
  
     [!code-cpp[wrl-logger-make#2](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_2.cpp)]  
  
### <a name="to-handle-construction-failure-for-the-basic-logger-component"></a>Para lidar com falhas de construção para o componente do agente de log básica  
  
1.  Use o código a seguir para substituir a definição do `CConsoleWriter` classe. Esta versão contém um membro privado de cadeia de caracteres variável e substituições de `RuntimeClass::RuntimeClassInitialize` método. `RuntimeClassInitialize` falha se a chamada para `SHStrDup` falhar.  
  
     [!code-cpp[wrl-logger-makeandinitialize#1](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_3.cpp)]  
  
2.  Use o código a seguir para substituir a definição de `wmain`. Essa versão usa `MakeAndInitialize` para instanciar o `CConsoleWriter` objeto e verifica o `HRESULT` resultados.  
  
     [!code-cpp[wrl-logger-makeandinitialize#2](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md)   
 [Microsoft::WRL::Make](../windows/make-function.md)   
 [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md)