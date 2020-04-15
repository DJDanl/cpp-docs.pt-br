---
title: Propriedades do depurador do Android (C++)
ms.date: 10/23/2017
ms.assetid: 789f7a1c-38b4-41d0-809b-14f4d96c8116
f1_keywords:
- VC.Project.AndroidDebugger.DebuggerType
- VC.Project.AndroidDebugger.AndroidDeviceID
- VC.Project.AndroidDebugger.PackagePath
- VC.Project.AndroidDebugger.LaunchActivity
ms.openlocfilehash: 23fd871f030593607cf374870b96e09d8bc2da7a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374206"
---
# <a name="android-debugger-properties"></a>Propriedades do depurador Android

| Propriedade | Descrição | Opções |
|--|--|--|
| Tipo de Depurador | Especifica o tipo de código a ser depurado. | **Somente nativo**<br /><br />**Somente Java** |
| Destino de depuração | Especifica o emulador ou o dispositivo a ser usado para depuração. Se nenhum emulador estiver sendo executado, use o Gerenciador de Dispositivos Virtuais (AVD) android para iniciar um dispositivo. |
| Pacote a ser inicializado | Especifica a localização do *.apk* que será depurado. Esta opção inicia o Pacote (APK) quando o aplicativo é depurado. |
| Atividade de inicialização | A atividade do Android usada para iniciar o aplicativo deve corresponder à que foi usada no manifesto. Pressione Aplicar para recuperar a lista do *AndroidManifest.xml* e preenche-la dinamicamente. |
| Caminhos de pesquisa de símbolo adicionais | Caminho de pesquisa adicional para símbolos de depuração. |
| Caminhos de pesquisa de origem Java adicionais | Caminhos de pesquisa adicionais para arquivos de origem Java. (Aplica-se somente quando o tipo de depurador é somente Java). |
