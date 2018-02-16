---
title: Aplicativos universais do Windows (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 357121cc-d390-4bae-b34a-39614861a9f4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a293f833de7bc575209089362bcaf146d074684b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="universal-windows-apps-c"></a>Aplicativos universais do Windows (C++)
Aplicativos de plataforma do Windows (UWP) universais incorporam um conjunto de princípios de design que enfatizam interfaces do usuário simples que são centralizadas em torno do conteúdo que ajusta automaticamente para diferentes tamanhos de telas em diferentes dispositivos. Você pode criar a interface do usuário na marcação XAML e o code-behind em C++ nativo. Você também pode criar componentes (DLLs) que podem ser consumidos por aplicativos da UWP que são escritos em outras linguagens. A superfície de API para aplicativos UWP é o tempo de execução do Windows, que é uma biblioteca bem fatorada que fornece uma ampla variedade de serviços do sistema operacional.  

> [!TIP]  
> Para Windows 10, você pode usar o conversor de aplicativo de área de trabalho para empacotar o aplicativo de área de trabalho existente para implantação por meio da Microsoft Store. Para obter mais informações, consulte [Usando o tempo de execução do Visual C++ em projeto Centennial](https://blogs.msdn.microsoft.com/vcblog/2016/07/07/using-visual-c-runtime-in-centennial-project) e [Traga seu aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) com a Ponte de Desktop](https://msdn.microsoft.com/en-us/windows/uwp/porting/desktop-to-uwp-root).
  
  
## <a name="uwp-apps-that-use-ccx"></a>Aplicativos da UWP que usam C + + CX  
  
|||  
|-|-|  
|[Referência de linguagem do Visual C++ (C + + CX)](../cppcx/visual-c-language-reference-c-cx.md)|Descreve o conjunto de extensões que simplificam o consumo de C++ de APIs do Windows Runtime e habilitar o tratamento de erros que se baseia em exceções.|  
|[Compilando aplicativos e bibliotecas (C++/CX)](../cppcx/building-apps-and-libraries-c-cx.md)|Descreve como criar DLLs e bibliotecas estáticas que podem ser acessadas de C + + CX aplicativo ou componente.|  
|[Tutorial: Criar seu primeiro aplicativo UWP usando C++](https://docs.microsoft.com/en-us/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)|Passo a passo que apresenta os conceitos básicos do desenvolvimento de aplicativos UWP em C++. (Ainda não foi atualizado para o desenvolvimento de UWP no Windows 10.)|  
|[Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)|Descreve como criar DLLs que outros componentes e aplicativos UWP podem consumir.|  
|[Desenvolvimento de jogos](https://docs.microsoft.com/en-us/windows/uwp/gaming/)|Descreve como usar o DirectX e C++ para criar jogos.|  
  
## <a name="uwp-apps-that-use-the-windows-runtime-c-template-library-wrl"></a>Aplicativos da UWP que usam a biblioteca de modelos C++ do Windows Runtime (WRL) 
 A biblioteca de modelos do Windows em tempo de execução C++ fornece as interfaces COM nível inferior pelo qual o código ISO C++ pode acessar o tempo de execução do Windows em um ambiente sem exceção. Na maioria dos casos, é recomendável que você use C + + CX em vez da biblioteca de modelos do Windows em tempo de execução C++ para desenvolvimento de aplicativos UWP. Para obter informações sobre a biblioteca de modelos do Windows em tempo de execução C++, consulte [biblioteca de modelo em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visual C++](../visual-cpp-in-visual-studio.md)

