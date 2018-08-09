---
title: Configurações do aplicativo, Assistente Win 32 projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.appwiz.win32.appset
dev_langs:
- C++
helpviewer_keywords:
- application settings [C++]
- Win32 Project Wizard, application settings
ms.assetid: d6b818f0-9b23-4793-a6c5-df1c8c594bad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 948b720df6094ddd4124bb496cabb3c83a3cacf0
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39652982"
---
# <a name="application-settings-win-32-project-wizard"></a>Configurações do aplicativo, Assistente de Projeto Win 32
Use esta página do Assistente para definir opções para o projeto do Win32.  
  
## <a name="application-type"></a>Tipo de aplicativo  
 Cria o tipo de aplicativo especificado.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Aplicativo de console**|Crie um aplicativo de console. Programas de console são desenvolvidos com [funções do Console](https://msdn.microsoft.com/library/ms813137.aspx), que fornecem suporte de modo de caractere nas janelas do console. O Visual C++ [bibliotecas de tempo de execução](../c-runtime-library/c-run-time-library-reference.md) também fornecem a saída e entrada do windows do console com funções de e/s padrão, como `printf_s()` e `scanf_s()`. Um aplicativo de console não tem nenhuma interface gráfica do usuário. Ele compila em um arquivo .exe e pode ser executado como um aplicativo autônomo da linha de comando.<br /><br /> Você pode adicionar suportam a MFC e ATL para um aplicativo de console.|  
|**Aplicativo do Windows**|Cria um programa Win32. Um programa Win32 é um aplicativo executável (EXE) escrito em C ou C++, usando chamadas à API do Win32 para criar uma interface gráfica do usuário.<br /><br /> Não é possível adicionar o MFC ou ATL oferecem suporte a um aplicativo do Windows.|  
|**DLL**|Cria uma biblioteca de vínculo dinâmico (DLL) do Win32. Uma DLL Win32 é um arquivo binário, escrito em C ou C++, que usa chamadas à API do Win32 em vez de classes do MFC e que atua como uma biblioteca compartilhada de funções que podem ser usados simultaneamente por vários aplicativos.<br /><br /> Não é possível adicionar o MFC ou ATL oferecem suporte a um aplicativo de DLL. Você pode indicar que a DLL exporta símbolos.|  
|**Biblioteca estática**|Cria uma biblioteca estática. Uma biblioteca estática é um arquivo que contém objetos e suas funções e os dados que vincula-se ao seu programa quando o arquivo executável é compilado. Este tópico explica como criar os arquivos iniciais e [propriedades do projeto](../ide/property-pages-visual-cpp.md) para uma biblioteca estática. Um arquivo de biblioteca estática fornece os seguintes benefícios:<br /><br /> -Uma biblioteca estática do Win32 será útil se o aplicativo que você está trabalhando em faz chamadas para a API do Win32 em vez de classes do MFC.<br />– O processo de vinculação é o mesmo se o restante do seu aplicativo do Windows é escrito em C ou C++.<br />-Você pode vincular uma biblioteca estática em um programa MFC ou a um programa não MFC.|  
  
## <a name="additional-options"></a>Opções adicionais  
 Define as opções para o aplicativo, dependendo do seu tipo e o suporte.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**Projeto vazio**|Especifica que os arquivos de projeto em branco. Se você tiver um conjunto de arquivos de código fonte (como arquivos. cpp, arquivos de cabeçalho, ícones, barras de ferramentas, caixas de diálogo e assim por diante) e deseja criar um projeto no ambiente de desenvolvimento do Visual C++, primeiro você deve criar um projeto em branco e adicione os arquivos ao projeto.<br /><br /> Essa seleção não está disponível para projetos de biblioteca estática.|  
|**Exportar símbolos**|Especifica que o projeto de DLL exporta símbolos.|  
|**Cabeçalho pré-compilado**|Especifica que o projeto de biblioteca estática usa um cabeçalho pré-compilado.|  
|Verificações do Security Development Lifecycle (SDL)|Para obter mais informações sobre o SDL, consulte [diretrizes de processo do Microsoft Security Development Lifecycle (SDL)](../build/reference/sdl-enable-additional-security-checks.md)|  
  
## <a name="add-support-for"></a>Adicionar suporte para  
 Adicione suporte para uma das bibliotecas fornecidas no Visual C++.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**ATL**|Compila para o suporte de projeto para classes na biblioteca ATL (Active Template). Para aplicativos de console Win32 somente.<br /><br /> **Observação** essa opção não indica suporte para adicionar objetos ATL usando a ATL assistentes de código. Você pode adicionar objetos ATL somente a projetos ATL ou dar suporte a projetos MFC com ATL.|  
|**MFC**|Compila para o suporte de projeto para a biblioteca Microsoft Foundation Class (MFC). Para aplicativos de console Win32 e apenas as bibliotecas estáticas.|  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do Win32](../windows/win32-application-wizard.md)   