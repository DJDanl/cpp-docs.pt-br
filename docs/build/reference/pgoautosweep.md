---
title: PgoAutoSweep | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
f1_keywords:
- PgoAutoSweep
- PogoAutoSweepA
- PogoAutoSweepW
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 988a73dd8c4ad6929ef04691ad1959df7ea7bdd7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32379491"
---
# <a name="pgoautosweep"></a>PgoAutoSweep

`PgoAutoSweep` salva as informações do contador de perfil atual em um arquivo e, em seguida, redefine os contadores. Use a função durante a Otimização Guiada por perfil treinamento para gravar todos os dados de perfil do programa em execução em um arquivo. PGC para uso posterior na compilação de otimização.

## <a name="syntax"></a>Sintaxe

```cpp
void PgoAutoSweep(const char* name);    // ANSI/MBCS
void PgoAutoSweep(const wchar_t* name); // UNICODE
```

### <a name="parameters"></a>Parâmetros

*name*<br/>
Uma cadeia de identifica para o arquivo. PGC salvo.

## <a name="remarks"></a>Comentários

Você pode chamar `PgoAutoSweep` do seu aplicativo para salvar e redefinir os dados de perfil a qualquer momento durante a execução do aplicativo. Em uma compilação instrumentada, `PgoAutoSweep` captura os dados de criação de perfil atuais, salva-o em um arquivo e redefine os contadores de perfil. É o equivalente a chamar o [pgosweep](pgosweep.md) comando em um ponto específico no seu executável. Em uma compilação otimizada, `PgoAutoSweep` é não operacional.

Os dados de contador de perfil salvas são colocados em um arquivo chamado *base_name*-*nome*! *valor*. PGC, onde *base_name* é o nome base do executável, *nome* é o parâmetro passado para `PgoAutoSweep`, e *valor* é um valor exclusivo, normalmente um número aumentando de forma monotônica, para evitar colisões de nome de arquivo.

Os arquivos. PGC criados pelo `PgoAutoSweep` devem ser mesclados em um arquivo. PGD a ser usado para criar um executável otimizado. Você pode usar o [pgomgr](pgomgr.md) comando para executar a mesclagem.

Você pode passar o nome do arquivo. PGD mesclados para o vinculador durante a compilação de otimização usando o **PGD =**_filename_ argumento para o [/USEPROFILE](useprofile.md) opção de vinculador, ou usando preterido **/PGD** opção de vinculador. Se você mesclar os arquivos. PGC em um arquivo denominado *base_name*PGD, você não precisa especificar o nome do arquivo na linha de comando, porque o vinculador pega este nome de arquivo por padrão.

O `PgoAutoSweep` função mantém a configuração de segurança do thread especificado quando a compilação instrumentada é criada. Se você usar a configuração padrão ou especificar o **NOEXACT** argumento para o [/GENPROFILE ou /FASTGENPROFILE]() opção de vinculador, chamadas para `PgoAutoSweep` não são thread-safe. O **exato** argumento cria um thread-safe e mais preciso, mas executável instrumentado, mais lento.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`PgoAutoSweep`|\<pgobootrun.h>|

O executável deve incluir o arquivo pgobootrun.lib nas bibliotecas do vinculado. O arquivo está incluído na instalação do Visual Studio, no diretório de bibliotecas do VC para cada arquitetura com suporte.

## <a name="example"></a>Exemplo

O exemplo a seguir usa `PgoAutoSweep` para criar dois. Arquivos PGC em pontos diferentes durante a execução. O primeiro contém dados que descreve o comportamento de tempo de execução até `count` é igual a 3, e o segundo contém os dados coletados depois desse ponto até apenas antes do encerramento do aplicativo.

```cpp
// pgoautosweep.cpp
// Compile by using: cl /c /GL /W4 /EHsc /O2 pgoautosweep.cpp
// Link to instrument: link /LTCG /genprofile pgobootrun.lib pgoautosweep.obj
// Run to generate data: pgoautosweep
// Merge data by using command line pgomgr tool:
// pgomgr /merge pgoautosweep-func1!1.pgc pgoautosweep-func2!1.pgc pgoautosweep.pgd
// Link to optimize: link /LTCG /useprofile pgobootrun.lib pgoautosweep.obj

#include <iostream>
#include <windows.h>
#include <pgobootrun.h>

void func2(int count)
{
    std::cout << "hello from func2 " << count << std::endl;
    Sleep(2000);
}

void func1(int count)
{
    std::cout << "hello from func1 " << count << std::endl;
    Sleep(2000);
}

int main()
{
    int count = 10;
    while (count--)
    {
        if (count < 3)
            func2(count);
        else
        {
            func1(count);
            if (count == 3)
            {
                PgoAutoSweep("func1");
            }
        }
    }
    PgoAutoSweep("func2");
}
```

Em um prompt de comando do desenvolvedor, compile o código em um arquivo de objeto usando este comando:

`cl /c /GL /W4 /EHsc /O2 pgoautosweep.cpp`

Em seguida, gere uma compilação instrumentada para treinamento usando este comando:

`link /LTCG /genprofile pgobootrun.lib pgoautosweep.obj`

O executável instrumentado para capturar os dados de treinamento. A saída de dados pelas chamadas para `PgoAutoSweep` é salva nos arquivos denominados func1 pgoautosweep! 1.pgc e pgoautosweep func2! 1.pgc. A saída do programa deve ser assim como ele é executado:

```Output
hello from func1 9
hello from func1 8
hello from func1 7
hello from func1 6
hello from func1 5
hello from func1 4
hello from func1 3
hello from func2 2
hello from func2 1
hello from func2 0
```

Mesclar os dados salvos em um banco de dados de treinamento do perfil, executando o **pgomgr** comando:

`pgoautosweep-func1!1.pgc pgoautosweep-func2!1.pgc`

A saída desse comando parecida com esta:

```Output
Microsoft (R) Profile Guided Optimization Manager 14.13.26128.0
Copyright (C) Microsoft Corporation. All rights reserved.

Merging pgoautosweep-func1!1.pgc
pgoautosweep-func1!1.pgc: Used  3.8% (22304 / 589824) of total space reserved.  0.0% of the counts were dropped due to overflow.
Merging pgoautosweep-func2!1.pgc
pgoautosweep-func2!1.pgc: Used  3.8% (22424 / 589824) of total space reserved.  0.0% of the counts were dropped due to overflow.
```

Agora você pode usar esses dados de treinamento para gerar uma compilação otimizada. Use este comando para criar o executável otimizado:

`link /LTCG /useprofile pgobootrun.lib pgoautosweep.obj`

```Output
Microsoft (R) Incremental Linker Version 14.13.26128.0
Copyright (C) Microsoft Corporation.  All rights reserved.

Merging pgoautosweep!1.pgc
pgoautosweep!1.pgc: Used  3.9% (22904 / 589824) of total space reserved.  0.0% of the counts were dropped due to overflow.
  Reading PGD file 1: pgoautosweep.pgd
Generating code

0 of 0 ( 0.0%) original invalid call sites were matched.
0 new call sites were added.
294 of 294 (100.00%) profiled functions will be compiled for speed
348 of 1239 inline instances were from dead/cold paths
294 of 294 functions (100.0%) were optimized using profile data
16870 of 16870 instructions (100.0%) were optimized using profile data
Finished generating code
```

## <a name="see-also"></a>Consulte também

[Otimizações guiadas por perfil](profile-guided-optimizations.md)<br/>
[pgosweep](pgosweep.md)<br/>
