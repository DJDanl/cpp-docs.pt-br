---
title: Propriedades do depurador doC++Android ()
ms.date: 10/23/2017
ms.assetid: 789f7a1c-38b4-41d0-809b-14f4d96c8116
f1_keywords:
- VC.Project.AndroidDebugger.DebuggerType
- VC.Project.AndroidDebugger.AndroidDeviceID
- VC.Project.AndroidDebugger.PackagePath
- VC.Project.AndroidDebugger.LaunchActivity
ms.openlocfilehash: 3ac896b384181e4e2b436368f39a343d35fe321a
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446888"
---
# <a name="android-debugger-properties"></a>Propriedades do depurador Android

| Propriedade | Descrição | Opções |
|--|--|--|
| {1&gt;{2&gt;Tipo de Depurador&lt;2}&lt;1} | Especifica o tipo de código a ser depurado. | **Somente nativo**<br /><br />**Somente Java** |
| Destino de depuração | Especifica o emulador ou o dispositivo a ser usado para depuração. Se nenhum emulador estiver em execução, use "Gerenciador de dispositivo virtual Android (AVD)" para iniciar um dispositivo. |
| Pacote a ser inicializado | Especifica o local do *.apk* que será depurado. Essa opção inicia o pacote (APK) quando o aplicativo é depurado. |
| Atividade de inicialização | A atividade do Android usada para iniciar o aplicativo deve corresponder à que foi usada no manifesto. Pressione Aplicar para recuperar a lista do *AndroidManifest.xml* e populá-la dinamicamente. |
| Caminhos de pesquisa de símbolo adicionais | Caminho de pesquisa adicional para símbolos de depuração. |
| Caminhos de pesquisa de origem Java adicionais | Caminhos de pesquisa adicionais para arquivos de origem Java. (Aplica-se somente quando o tipo de depurador é somente Java). |
