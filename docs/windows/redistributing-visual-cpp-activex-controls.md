---
title: Redistribuindo controles ActiveX do Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- controls [C++], redistributing
- controls [C++], distributing
ms.assetid: eefbb7e4-d28c-4c35-98bf-d9540cfaae83
ms.openlocfilehash: 4c7806502024789ed41f3043d7db6c87c7c71ee3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359875"
---
# <a name="redistributing-visual-c-activex-controls"></a>Redistribuindo controles ActiveX do Visual C++

O Visual C++ 6.0 fornece controles ActiveX que você pode usar em aplicativos que redistribuirá em seguida. Esses controles não estão mais incluídos no Visual C++. De acordo com os contratos de licença do Visual C++ 6.0, você pode redistribuir esses controles com aplicativos desenvolvidos no Visual C++.

> [!NOTE]
> A Microsoft deixou de dar suporte ao Visual C++ 6.0.

Para obter uma lista dos controles ActiveX redistribuíveis do Visual C++ 6.0, confira Common\Redist\Redist.txt no Disco 1 do CD do produto do Visual C++ 6.0.

Ao distribuir aplicativos, você precisará instalar e registrar o .ocx para o controle ActiveX (usando Regsvr32.exe). Além disso, você deverá verificar se o computador de destino tem as versões atuais dos seguintes arquivos do sistema (um asterisco indica que o arquivo precisa ser registrado):

- Asycfilt.dll

- Comcat.dll \*

- Oleaut32.dll \*

- Olepro32.dll \*

- Stdole2.tlb

Se essas DLLs não estão disponíveis no sistema de destino, você precisa atualizá-las usando o mecanismo indicado para atualização do sistema operacional correspondente. Você pode baixar os pacotes de [http://windowsupdate.microsoft.com](https://windowsupdate.microsoft.com)serviço mais recentes para sistemas operacionais Windows a partir de .

Ao usar um controle ActiveX que se conecta a um banco de dados, também é necessário replicar o nome da fonte de dados no computador de destino. Faça isso de forma programática com funções como `ConfigDSN`.

Alguns controles ActiveX redistribuíveis têm dependências adicionais. Para cada arquivo .ocx na pasta Os\System no CD do produto do Visual C++ 6.0, também há um arquivo .dep. Para cada arquivo .ocx que você deseja redistribuir, procure uma ou mais entradas USES no arquivo .dep correspondente. Se um arquivo está listado, verifique se o arquivo está no computador de destino. As DLLs que dão suporte direto a um arquivo .ocx precisam ser registradas. (Para que o Regsvr32.exe tenha sucesso, o computador de destino deve primeiro conter todas as DLLs que o controle carrega estáticamente.) Além disso, se uma DLL listada como uma dependência também tiver um arquivo .dep na pasta Os\System no CD Visual C++ 6.0, você também deve investigar esse arquivo .dep para entradas USE.

## <a name="see-also"></a>Confira também

[Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md)
