---
title: Redistribuindo controles ActiveX do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [C++], redistributing
- controls [C++], distributing
ms.assetid: eefbb7e4-d28c-4c35-98bf-d9540cfaae83
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5eea5ef50427e7398246d8da3d7977bb714d9b54
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46383877"
---
# <a name="redistributing-visual-c-activex-controls"></a>Redistribuindo controles ActiveX do Visual C++

O Visual C++ 6.0 fornece controles ActiveX que você pode usar em aplicativos que redistribuirá em seguida. Esses controles não estão mais incluídos no Visual C++. De acordo com os contratos de licença do Visual C++ 6.0, você pode redistribuir esses controles com aplicativos desenvolvidos no Visual C++.

> [!NOTE]
>  A Microsoft deixou de dar suporte ao Visual C++ 6.0.

Para obter uma lista dos controles ActiveX redistribuíveis do Visual C++ 6.0, confira Common\Redist\Redist.txt no Disco 1 do CD do produto do Visual C++ 6.0.

Ao distribuir aplicativos, você precisará instalar e registrar o .ocx para o controle ActiveX (usando Regsvr32.exe). Além disso, você deverá verificar se o computador de destino tem as versões atuais dos seguintes arquivos do sistema (um asterisco indica que o arquivo precisa ser registrado):

- Asycfilt.dll

- Comcat.dll \*

- Oleaut32.dll \*

- Olepro32.dll \*

- Stdole2.tlb

Se essas DLLs não estão disponíveis no sistema de destino, você precisa atualizá-las usando o mecanismo indicado para atualização do sistema operacional correspondente. Baixe os últimos service packs para sistemas operacionais Windows em [http://windowsupdate.microsoft.com](http://windowsupdate.microsoft.com).

Ao usar um controle ActiveX que se conecta a um banco de dados, também é necessário replicar o nome da fonte de dados no computador de destino. Faça isso de forma programática com funções como `ConfigDSN`.

Alguns controles ActiveX redistribuíveis têm dependências adicionais. Para cada arquivo .ocx na pasta Os\System no CD do produto do Visual C++ 6.0, também há um arquivo .dep. Para cada arquivo .ocx que você deseja redistribuir, procure uma ou mais entradas USES no arquivo .dep correspondente. Se um arquivo está listado, verifique se o arquivo está no computador de destino. As DLLs que dão suporte direto a um arquivo .ocx precisam ser registradas. (Para que Regsvr32.exe seja bem-sucedido, primeiro, o computador de destino precisa conter todas as DLLs estaticamente carregadas pelo controle.) Além disso, se uma DLL que está listada como uma dependência também tem um arquivo .dep na pasta Os\System no CD do Visual C++ 6.0, investigue também se há entradas USES nesse arquivo .dep.

## <a name="see-also"></a>Consulte também

[Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md)