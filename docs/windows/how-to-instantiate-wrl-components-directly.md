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
ms.openlocfilehash: 133f0f4ee4efed71c530c7e9e8c367c7d2031433
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013269"
---
# <a name="how-to-instantiate-wrl-components-directly"></a>Como instanciar componentes WRL diretamente
Saiba como usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL)[Microsoft::WRL::Make](../windows/make-function.md) e [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md) funções para criar uma instância de um componente do módulo que Define a ele.  
  
 Instanciando componentes diretamente, você pode reduzir a sobrecarga quando você não precisa fábricas de classes ou outros mecanismos. Você pode instanciar um componente diretamente em ambos os aplicativos da plataforma Universal do Windows e em aplicativos da área de trabalho.  
  
Para saber como usar a biblioteca de modelos de C++ de tempo de execução do Windows para criar um componente COM clássico e criar uma instância de um aplicativo de área de trabalho externo, consulte [como: criar um componente COM clássico](../windows/how-to-create-a-classic-com-component-using-wrl.md).  
  
 Este documento mostra dois exemplos. O primeiro exemplo usa o `Make` função para criar uma instância de um componente. O segundo exemplo usa o `MakeAndInitialize` função para criar uma instância de um componente que pode falhar durante a construção. (Como COM normalmente usa valores HRESULT, em vez de exceções, para indicar erros, um tipo COM geralmente não lançar de seu construtor. `MakeAndInitialize` permite que um componente validar seus argumentos de construção por meio de `RuntimeClassInitialize` método.) Ambos os exemplos definem uma interface básica do agente de log e implementação-la definindo uma classe que grava mensagens no console.  
  
> [!IMPORTANT]
>  Não é possível usar o **novo** operador instanciar os componentes da biblioteca de modelos de C++ de tempo de execução do Windows. Portanto, é recomendável que você sempre use `Make` ou `MakeAndInitialize` para instanciar um componente diretamente.  
  
### <a name="to-create-and-instantiate-a-basic-logger-component"></a>Para criar e instanciar um componente básico do agente de log  
  
1.  No Visual Studio, crie uma **aplicativo do Console Win32** projeto. Nomeie o projeto, por exemplo, *WRLLogger*.  
  
2.  Adicionar um **arquivo Midl (. idl)** do arquivo ao projeto, nomeie o arquivo `ILogger.idl`e, em seguida, adicione este código:  
  
     [!code-cpp[wrl-logger-make#1](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_1.idl)]  
  
3.  Use o seguinte código para substituir o conteúdo de `WRLLogger.cpp`.  
  
     [!code-cpp[wrl-logger-make#2](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_2.cpp)]  
  
### <a name="to-handle-construction-failure-for-the-basic-logger-component"></a>Para lidar com falhas de construção para o componente Agente básico  
  
1.  Use o seguinte código para substituir a definição do `CConsoleWriter` classe. Esta versão contém um membro particular de cadeia de caracteres variável e substitui o `RuntimeClass::RuntimeClassInitialize` método. `RuntimeClassInitialize` falhará se a chamada para `SHStrDup` falhar.  
  
     [!code-cpp[wrl-logger-makeandinitialize#1](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_3.cpp)]  
  
2.  Use o seguinte código para substituir a definição de `wmain`. Essa versão usa `MakeAndInitialize` para instanciar o `CConsoleWriter` do objeto e verifica o resultado HRESULT.  
  
     [!code-cpp[wrl-logger-makeandinitialize#2](../windows/codesnippet/CPP/how-to-instantiate-wrl-components-directly_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md)   
 [Microsoft::WRL::Make](../windows/make-function.md)   
 [Microsoft::WRL::Details::MakeAndInitialize](../windows/makeandinitialize-function.md)