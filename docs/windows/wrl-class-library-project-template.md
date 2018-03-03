---
title: Modelo de projeto de biblioteca de classes WRL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
ms.assetid: 628b0852-89e5-44f8-bf58-a09762bda15c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 13fc476f696bdd2cb17ed58c496c63747db90322
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="wrl-class-library-project-template"></a>Modelo de projeto de biblioteca de classes WRL
Se você usar o Visual Studio para gravar um projeto de biblioteca de modelo em C++ Windows Runtime (WRL), você pode simplificar muito a tarefa ao baixar o modelo de projeto de biblioteca de classes WRL.  
  
> [!NOTE]
>  Se você tiver que atualizar manualmente as configurações de projeto para um projeto existente, consulte [DLLs (C + + CX)](http://msdn.microsoft.com/library/windows/apps/hh699881\(v=vs.110\).aspx).  
  
## <a name="download-the-wrl-project-template"></a>Baixe o modelo de projeto WRL  
 O Visual Studio não fornece um modelo para projetos de biblioteca de modelos C++ do Windows Runtime. Aqui está como fazer download de um modelo de projeto que cria uma biblioteca de classe básica para aplicativos de plataforma Universal do Windows com a biblioteca de modelos C++ do Windows Runtime.  
  
#### <a name="to-download-the-wrl-project-template"></a>Para baixar o modelo de projeto WRL  
  
1.  Na barra de menus, escolha **arquivo**, **novo projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo, selecione **Online**e, em seguida, selecione **modelos**.  
  
3.  No **pesquisar modelos online** caixa no canto superior direito, tipo `WRL Class Library`. Quando o modelo é exibido nos resultados da pesquisa, escolha o **Okey** botão.  
  
4.  No **baixar e instalar** dos termos da caixa de diálogo, se você concordar com o licenciamento, escolha o **instalar** botão.  
  
5.  Depois de instala o modelo, crie um projeto, escolhendo **arquivo**, **novo projeto**e, em seguida, selecionando o `WRLClassLibrary` modelo. O projeto cria uma DLL.  
  
## <a name="examples-that-use-the-project-template"></a>Exemplos que usam o modelo de projeto  
 Leitura [passo a passo: Criando um componente de tempo de execução do Windows básico](../windows/walkthrough-creating-a-basic-windows-runtime-component-using-wrl.md) para obter um exemplo que usa este modelo para criar um componente de tempo de execução do Windows.  
  
## <a name="what-the-project-template-provides"></a>O que fornece o modelo de projeto  
 Fornece o modelo de projeto:  
  
-   um arquivo. IDL que declara os atributos MIDL para uma interface básica sua implementação de classe. Aqui está um exemplo.  
  
     [!code-cpp[wrl-project-template#1](../windows/codesnippet/CPP/wrl-class-library-project-template_1.idl)]  
  
-   um arquivo. cpp que define a implementação da classe. Aqui está um exemplo.  
  
     [!code-cpp[wrl-project-template#2](../windows/codesnippet/CPP/wrl-class-library-project-template_2.cpp)]  
  
     O [RuntimeClass](../windows/runtimeclass-class.md) ajuda a gerenciar a referência global de todos os objetos no módulo de classe base e declara os métodos do [IUnknown](http://msdn.microsoft.com/en-us/33f1d79a-33fc-4ce5-a372-e08bda378332) e [IInspectable](http://msdn.microsoft.com/en-us/0657e51f-d4c0-46c6-927d-b01e54b6846c) interfaces. O [InspectableClass](../windows/inspectableclass-macro.md) macro implementa `IUnknown` e `IInspectable`. O [ActivatableClass](../windows/activatableclass-macros.md) macro cria uma fábrica de classes que cria instâncias da classe.  
  
-   Exporta um arquivo chamado module.cpp que define a biblioteca `DllMain`, `DllCanUnloadNow`, `DllGetActivationFactory`, e `DllGetClassObject`.  
  
## <a name="see-also"></a>Consulte também  
 [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)