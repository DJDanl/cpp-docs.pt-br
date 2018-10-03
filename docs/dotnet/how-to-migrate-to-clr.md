---
title: 'Como: migrar para - clr | Microsoft Docs'
ms.custom: get-started-article
ms.date: 09/18/2018
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- upgrading Visual C++ applications, /clr compiler option
- compiling native code [C++]
- interoperability [C++], /clr compiler option
- interop [C++], /clr compiler option
- migration [C++], /clr compiler option
- /clr compiler option [C++], porting to
ms.assetid: c9290b8b-436a-4510-8b56-eae51f4a9afc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 165ea5b42ea4e293eb60b7a798778e3a461e0385
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235445"
---
# <a name="how-to-migrate-to-clr"></a>Como migrar para /clr

Este tópico discute problemas que ocorrem durante a compilação de código nativo com **/clr** (consulte [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações). **/CLR** permite que o código C++ nativo invocar e ser invocado a partir de assemblies do .NET, além de outro código C++ nativo. Ver [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md) e [nativo e interoperabilidade do .NET](../dotnet/native-and-dotnet-interoperability.md) para obter mais informações sobre as vantagens de compilação com **/clr**.

## <a name="known-issues-compiling-library-projects-with-clr"></a>Conhecidos problemas de compilação de projetos de biblioteca com /clr

O Visual Studio contém alguns problemas conhecidos ao compilar projetos de biblioteca com **/clr**:

- Seu código pode consultar tipos em tempo de execução com [CRuntimeClass::FromName](../mfc/reference/cruntimeclass-structure.md#fromname). No entanto, se um tipo estiver em um MSIL. dll (compilado com **/clr**), a chamada para `FromName` poderá falhar se ele ocorrer antes que os construtores estáticos é executada no arquivo. dll gerenciado (você não verá esse problema se a chamada de FromName ocorre depois que tiver de código executado na gerenciado. dll). Para contornar esse problema, você pode forçar a construção do construtor estático gerenciado pela definição de uma função no arquivo. dll gerenciado, exportá-lo e invocá-lo em um aplicativo nativo do MFC. Por exemplo:

    ```
    // MFC extension DLL Header file:
    __declspec( dllexport ) void EnsureManagedInitialization () {
       // managed code that won't be optimized away
       System::GC::KeepAlive(System::Int32::MaxValue);
    }
    ```

## <a name="compile-with-visual-c"></a>Compilar com o Visual C++

Antes de usar **/clr** em qualquer módulo em seu projeto, primeiro compilar e vincular o projeto nativo com o Visual Studio 2010.

As etapas a seguir, seguidas na ordem, fornecem o caminho mais fácil para um **/clr** compilação. É importante compilar e executar seu projeto depois de cada uma dessas etapas.

### <a name="versions-prior-to-visual-c-2003"></a>Versões anteriores do Visual C++ 2003

Se você estiver atualizando para o Visual Studio 2010 de uma versão anterior à Visual C++ 2003, você poderá ver erros de compilador relacionados à conformidade padrão C++ aprimorada no Visual C++ 2003

### <a name="upgrading-from-visual-c-2003"></a>Atualizando do Visual C++ 2003

Projetos anteriores criados com o Visual C++ 2003 também primeiro devem ser compilados sem **/clr** Visual Studio agora tem maior conformidade com ANSI/ISO e algumas alterações. É a alteração que provavelmente exigirá mais atenção [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md). O código que usa o CRT é muito provável produzir os avisos de depreciação. Esses avisos podem ser suprimidos, mas a migração para o novo [Security-Enhanced versões das funções de CRT](../c-runtime-library/security-enhanced-versions-of-crt-functions.md) é preferencial, pois eles fornecem maior segurança e podem revelar problemas de segurança em seu código.

### <a name="upgrading-from-managed-extensions-for-c"></a>Atualizando de extensões gerenciadas para C++

O código escrito com extensões gerenciadas para C++ a partir do Visual Studio 2005, não será compilado sob **/clr**.

## <a name="convert-c-code-to-c"></a>Converter o código C para C++

Embora o Visual Studio compilará os arquivos de C, é necessário convertê-las em C++ para um **/clr** compilação. O nome do arquivo real não precisa ser alterado; Você pode usar **/Tp** (consulte [/Tc, /Tp, /TC, /TP (especificar tipo de arquivo de origem)](../build/reference/tc-tp-tc-tp-specify-source-file-type.md).) Observe que, embora os arquivos de código-fonte C++ são necessários para **/clr**, não é necessário reconsiderar o código para usar o paradigma orientado a objeto.

Código C é muito provavelmente exigirá alterações quando compilado como um arquivo C++. As regras de segurança de tipos C++ são estritos, portanto, conversões de tipo devem ser feitas explícitas com conversões. Por exemplo, malloc retorna um ponteiro nulo, mas pode ser atribuído a um ponteiro para qualquer tipo em C com uma conversão:

```
int* a = malloc(sizeof(int));   // C code
int* b = (int*)malloc(sizeof(int));   // C++ equivalent
```

Ponteiros de função também são estritamente fortemente tipada em C++, o código C a seguir exige a modificação. No C++, é melhor criar um `typedef` que define o tipo de ponteiro de função e, em seguida, usar esse tipo para converter ponteiros de função:

```
NewFunc1 = GetProcAddress( hLib, "Func1" );   // C code
typedef int(*MYPROC)(int);   // C++ equivalent
NewFunc2 = (MYPROC)GetProcAddress( hLib, "Func2" );
```

C++ também requer que funções ser prototipado ou completamente definida antes que possam ser referenciados ou invocados.

Identificadores usados no código C e que são palavras-chave no C++ (como `virtual`, `new`, `delete`, `bool`, `true`, `false`, etc.) deve ser renomeado. Em geral, isso pode ser feito com operações de pesquisa e substituição simples.

```
COMObj1->lpVtbl->Method(COMObj, args);  // C code
COMObj2->Method(args);  // C++ equivalent
```

## <a name="reconfigure-project-settings"></a>Reconfigurar as configurações do projeto

Depois que seu projeto compila e executa no Visual Studio 2010, você deve criar novas configurações de projeto para **/clr** em vez de modificar as configurações padrão. **/CLR** é incompatível com algumas opções de compilador e criar configurações separadas permite que você compilar seu projeto como nativo ou gerenciado. Quando **/clr** está selecionado na caixa de diálogo de páginas de propriedade, configurações do projeto não é compatíveis com **/clr** são desabilitados (e as opções desabilitadas não são restauradas automaticamente se **/clr** está selecionado subsequentemente).

### <a name="create-new-project-configurations"></a>Criar novas configurações de projeto

Você pode usar **copiar configurações de** opção a **caixa de diálogo de configuração do novo projeto** (**compilar** > **doConfigurationManager**  >  **Configuração da solução ativa** > **New**) para criar uma configuração de projeto com base em suas configurações de projeto existente. Fazer isso vez para a configuração de depuração e outra para a configuração de versão. As alterações subsequentes, em seguida, podem ser aplicadas para o **/clr** -configurações específicas, deixando as configurações de projeto originais intactos.

Projetos que usam regras de compilação personalizada podem exigir atenção extra.

Essa etapa tem implicações diferentes para projetos que usam makefiles. Neste caso, um destino de compilação separado pode ser configurado ou versão específica do **/clr** compilação pode ser criada a partir de uma cópia do original.

### <a name="change-project-settings"></a>Alterar as configurações de projeto

**/CLR** podem ser selecionadas no ambiente de desenvolvimento, seguindo as instruções [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md). Conforme mencionado anteriormente, esta etapa desabilitará automaticamente as configurações conflitantes do projeto.

> [!NOTE]
>  Ao atualizar uma biblioteca gerenciada ou o projeto de serviço web do Visual C++ 2003, o **/Zl** será de opção de compilador adicionado para o **linha de comando** página de propriedades. Isso fará com que LNK2001. Remova **/Zl** da **linha de comando** página de propriedades para resolver. Ver [/Zl (omitir nome da biblioteca padrão)](../build/reference/zl-omit-default-library-name.md) e [trabalhando com propriedades do projeto](../ide/working-with-project-properties.md) para obter mais informações. Ou, adicionar Msvcrt. lib e msvcmrt para o vinculador **dependências adicionais** propriedade.

Para projetos criados com makefiles, opções do compilador incompatível devem estar desabilitadas manualmente uma vez **/clr** é adicionado. Consulte /[/clr restrições](../build/reference/clr-restrictions.md) para obter informações sobre opções de compilador que não são compatíveis com **/clr**.

### <a name="precompiled-headers"></a>Cabeçalhos Pré-compilados

Cabeçalhos pré-compilados são suportados sob **/clr**. No entanto, se você compilar apenas alguns dos seus arquivos CPP com **/clr** (Compilando o restante como nativo) algumas alterações será necessárias porque gerados com cabeçalhos pré-compilados **/clr** não são compatíveis com aqueles gerado sem **/clr**. Essa incompatibilidade é devido ao fato de que **/clr** gera e requer metadados. Módulos compilados **/clr** não é possível, portanto, usar cabeçalhos pré-compilados que não incluem os metadados e não **/clr** módulos não é possível usar arquivos de cabeçalho pré-compilado que contêm dados de metadados.

A maneira mais fácil compilar um projeto que alguns módulos são compilados **/clr** é desabilitar totalmente o cabeçalhos pré-compilados. (No diálogo de páginas de propriedades do projeto, abra o nó C/C++ e selecione cabeçalhos pré-compilados. Em seguida, altere a propriedade de criar/usar cabeçalho pré-compilado para "Não usando cabeçalhos pré-compilados".)

No entanto, especialmente para projetos grandes, cabeçalhos pré-compilados fornecem muito maior velocidade de compilação, para que desabilitar esse recurso não é desejável. Nesse caso, é melhor configurar o **/clr** e não **/clr** arquivos para usar cabeçalhos pré-compilados separados. Isso pode ser feito em uma única etapa, a seleção de vários módulos a serem compilados **/clr** usando **Gerenciador de soluções**, clicando duas vezes no grupo e selecionar propriedades. Em seguida, altere as propriedades a criar/usar PCH através de arquivo e o arquivo de cabeçalho pré-compilado para usar um nome de arquivo de cabeçalho diferente e um arquivo PCH, respectivamente.

## <a name="fixing-errors"></a>Correção de erros

Compilando com **/clr** pode resultar em erros de compilador, vinculador ou tempo de execução. Esta seção discute os problemas mais comuns.

### <a name="metadata-merge"></a>Mesclagem de metadados

Versões diferentes dos tipos de dados podem causar o vinculador falhar, pois os metadados gerados para os dois tipos não correspondem. (Isso é normalmente causado quando os membros de um tipo são definidos condicionalmente, mas as condições não forem os mesmos para todos os arquivos CPP que usam o tipo.) Nesse caso, o vinculador falha, relatórios apenas o nome do símbolo e o nome do segundo arquivo OBJ onde o tipo foi definido. Geralmente é útil girar a ordem que os arquivos OBJ são enviados para o vinculador para descobrir o local da outra versão do tipo de dados.

### <a name="loader-lock-deadlock"></a>Deadlock de bloqueio do carregador

O "deadlock de bloqueio do carregador" podem ocorrer, mas é determinístico e é detectado e reportado em tempo de execução. Ver [inicialização de Assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md) para informações detalhadas, orientação e soluções.

### <a name="data-exports"></a>Exportações de dados

Exportando dados DLL é propenso a erro e não é recomendado. Isso ocorre porque a seção de dados de uma DLL não é garantida para ser inicializado até que alguma parte gerenciado da DLL tenha sido executado. Com os metadados de referência [# diretiva using](../preprocessor/hash-using-directive-cpp.md).

### <a name="type-visibility"></a>Visibilidade de tipo

Tipos nativos são private por padrão. Isso pode resultar em um tipo nativo não ficarem visíveis fora da DLL. Resolver esse erro, adicionando `public` a esses tipos.

### <a name="floating-point-and-alignment-issues"></a>Problemas de alinhamento e o ponto de flutuante

`__controlfp` Não há suporte para o common language runtime (consulte [_control87, controlfp, \__control87_2](../c-runtime-library/reference/control87-controlfp-control87-2.md) para obter mais informações). O CLR também respeitará [alinhar](../cpp/align-cpp.md).

### <a name="com-initialization"></a>Inicialização do COM

O Common Language Runtime inicializa COM automaticamente quando um módulo é inicializado (quando o COM é inicializado automaticamente ele tem feito isso como MTA). Como resultado, inicializar explicitamente COM gera códigos de retorno que indica que o COM já foi inicializado. A tentativa de inicializar explicitamente COM um modelo de threading do CLR já inicializada COM a outro modelo de threading pode causar falha no aplicativo.

O common language runtime inicia COM como MTA por padrão. Use [/CLRTHREADATTRIBUTE (definir atributo de Thread CLR)](../build/reference/clrthreadattribute-set-clr-thread-attribute.md) modificar isso.

### <a name="performance-issues"></a>Problemas de desempenho

Você pode ver o desempenho reduzido quando os métodos de C++ nativos gerados para MSIL são chamados indiretamente (chamadas de função virtual ou usando ponteiros de função). Para saber mais sobre isso, consulte [dupla](../dotnet/double-thunking-cpp.md).

Ao mover de nativo para MSIL, você observará um aumento no tamanho do seu conjunto de trabalho. Isso ocorre porque o common language runtime fornece muitos recursos para garantir que os programas executados corretamente. Se sua **/clr** não está sendo executado corretamente, você talvez queira habilitar C4793 (desativado por padrão), consulte [aviso do compilador (nível 1 e 3) C4793](../error-messages/compiler-warnings/compiler-warning-level-1-and-3-c4793.md) para obter mais informações.

### <a name="program-crashes-on-shutdown"></a>Falhas do programa no desligamento

Em alguns casos, o CLR pode encerrar antes da conclusão do seu código gerenciado em execução. Usando o `std::set_terminate` e `SIGTERM` podem causar isso. Ver [constantes de sinal](../c-runtime-library/signal-constants.md) e [set_terminate](../c-runtime-library/abnormal-termination.md) para obter mais informações.

## <a name="using-new-visual-c-features"></a>Usando os novos recursos do Visual C++

Depois de seu aplicativo compila, links e executado, você pode começar a usar recursos do .NET em qualquer módulo compilado com **/clr**. Para obter mais informações, consulte [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md).

Se você usou extensões gerenciadas para C++, você pode converter seu código para usar a nova sintaxe. Para obter detalhes sobre como converter extensões gerenciadas para C++, consulte [C + + c++ Primer de migração](../dotnet/cpp-cli-migration-primer.md).

Para obter informações sobre programação no Visual C++ .NET, consulte:

- [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

- [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)

- [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
