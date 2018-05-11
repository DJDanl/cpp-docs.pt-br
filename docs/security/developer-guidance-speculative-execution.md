---
title: Diretrizes para desenvolvedores de C++ para canais de lado especulativo execução | Microsoft Docs
ms.custom: ''
ms.date: 05/03/2018
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, security
- security [C++]
- security [C++], best practices
- Spectre
- CVE-2017-5753
- Speculative Execution
author: mamillmsft
ms.author: mikeblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0a7e7ddb51f07f7fe6be1da017d8feae9cc4919e
ms.sourcegitcommit: 96cdc2da0d8c3783cc2ce03bd280a5430e1ac01d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2018
---
# <a name="c-developer-guidance-for-speculative-execution-side-channels"></a>Diretrizes para desenvolvedores de C++ para especulativo canais do lado de execução

Este artigo contém orientações para desenvolvedores para ajudá-lo a identificar e atenuar vulnerabilidades de hardware de canal execução especulativa lado no software de C++. Essas vulnerabilidades podem divulgar informações confidenciais entre limites de confiança e podem afetar o software que é executado em processadores que suportam especulativa, fora de ordem de execução de instruções. Essa classe de vulnerabilidades primeiro descrito em janeiro de 2018 e informações adicionais e diretrizes que podem ser encontradas em [comunicado de segurança da Microsoft](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002).

As diretrizes fornecidas por este artigo está relacionada à classe de vulnerabilidades representado por CVE-2017-5753, também conhecido como variante Spectre 1. Essa classe de vulnerabilidade de hardware está relacionado a canais de lado que podem surgir devido à execução especulativa que ocorre como resultado misprediction uma ramificação condicional. O compilador do Visual C++ no Visual Studio de 2017 (começando com a versão 15.5.5) inclui suporte para o `/Qspectre` switch fornece uma redução do tempo de compilação para um conjunto limitado de vulneráveis padrões de codificação relacionados ao CVE-2017-5753. A documentação para o [/Qspectre](https://docs.microsoft.com/en-us/cpp/build/reference/qspectre) sinalizador fornece mais informações sobre seus efeitos e uso. 

Uma introdução acessível a vulnerabilidades de canal do lado de execução especulativa pode ser encontrada na apresentação intitulada [o caso de Spectre e sobrecarga](https://www.youtube.com/watch?v=_4O0zMW-Zu4) por uma das equipes de pesquisa que esses problemas descobertos.

## <a name="what-are-speculative-execution-side-channel-hardware-vulnerabilities"></a>Quais são as vulnerabilidades do hardware especulativo execução lado canal?

CPUs modernas fornecem níveis mais altos de desempenho, fazendo uso de especulativo e fora de ordem de execução de instruções. Por exemplo, isso geralmente é feito pela prevendo o destino de ramificações (condicional e indrect) que permite que a CPU começar a forma especulativa executando as instruções no destino de branch previstas, evitando uma pausa até que o destino de ramificação real é resolvido. Se a CPU mais tarde descobre que ocorreu uma misprediction, todos os estados de máquina que foi computado forma especulativa serão descartados. Isso garante que não há nenhum arquitetonicamente visíveis efeitos da especulação previstas incorretamente.

Durante a execução especulativa não afeta o estado de visibilidade architecturaly, ele pode deixar residuais rastreamentos em estado não-arquitetura, como os vários caches que são usados pela CPU. É esses rastreamentos residuais de execução especulativa que pode dar origem às vulnerabilidades do canal do lado. Para entender isso melhor, considere o seguinte fragmento de código que fornece um exemplo de CVE-2017-5753 (ignorar verificar limites):

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

Neste exemplo, `ReadByte` é fornecido um buffer, um tamanho de buffer e um índice em buffer. O parâmetro de índice, conforme especificado por `untrusted_index`, é fornecido por um menor contexto privilegiado, como um processo não administrativas. Se `untrusted_index` é menor que `buffer_size`, em seguida, o caractere no índice é lido de `buffer` e usado para índices em uma região compartilhada de memória referenciada por `shared_buffer`.

De uma perspectiva arquitetônica, esta sequência de código é perfeitamente segura, é garantido que `untrusted_index` sempre será menor que `buffer_size`. No entanto, na presença de execução especulativa, é possível que a CPU mispredict a ramificação condicional e executar o corpo do se instrução mesmo quando `untrusted_index` é maior que ou igual a `buffer_size`. Consequentemente, a CPU forma especulativa pode ler um byte fora dos limites do `buffer` (que pode ser um segredo) e, em seguida, pode usar esse valor de byte para o endereço de uma carga subsequente por meio de computação `shared_buffer`. 

Enquanto a CPU eventualmente detectará essa misprediction, efeitos colaterais da residuais poderão ser deixados no cache de CPU que revelam informações sobre o valor de byte que foi lido fora dos limites de `buffer`. Esses efeitos colaterais podem ser detectados por um menor contexto privilegiado em execução no sistema, rapidez sondando cada cache linha `shared_buffer` é acessada. As etapas que podem ser tomadas para fazer isso são:

1. **Invocar `ReadByte` várias vezes com `untrusted_index` sendo menor `buffer_size`** . O contexto de ataque pode fazer com que o contexto da vítima invocar `ReadByte` (por exemplo, através de RPC), de modo que o indicador de ramificação é treinado para ser executada não como `untrusted_index` é menor que `buffer_size`.

2. **Liberar todas as linhas de cache no `shared_buffer`** . O contexto de ataque deve liberar todas as linhas de cache na região compartilhada de memória referenciada por `shared_buffer`. Desde que a região de memória é compartilhada, isso é simples e pode ser realizado usando intrínsecos, como `_mm_clflush`.

3. **Invocar `ReadByte` com `untrusted_index` maior `buffer_size`** . O contexto de ataque faz com que o contexto da vítima invocar `ReadByte` , de modo que prevê incorretamente que a ramificação não será executada. Isso faz com que o processador de forma especulativa executar o corpo do se bloco com `untrusted_index` maior `buffer_size`, assim, à esquerda de uma leitura fora dos limites de `buffer`. Consequentemente, `shared_buffer` é indexado usando um valor potencialmente secreto que foi lido fora dos limites, fazendo com que a linha de cache do respectivos sejam carregados pela CPU.

4. **Ler cada linha de cache no `shared_buffer` para ver o que é acessado mais rapidamente**. O contexto de ataque pode ler cada linha de cache no `shared_buffer` e detectar a linha de cache que carrega significativamente mais rápido do que os outros. Esta é a linha de cache que provavelmente foram levadas etapa 3. Como há uma relação de 1:1 entre a linha de cache e o valor de byte neste exemplo, isso permite que o invasor deduzir o valor real do byte lido fora dos limites.

As etapas acima fornecem um exemplo de como usar uma técnica conhecida como limpeza + RECARREGAMENTO em conjunto com uma instância do CVE-2017-5753 a exploração.

## <a name="what-software-scenarios-can-be-impacted"></a>Os cenários de software podem ser afetados?

Desenvolvimento de software seguro usando um processo semelhante a [Security Development Lifecycle](https://www.microsoft.com/en-us/sdl/) (SDL) normalmente exige que os desenvolvedores identificam os limites de confiança que existem em seu aplicativo. Existe um limite de confiança em lugares onde um aplicativo pode interagir com os dados fornecidos por um contexto menos confiável, como um processo de modo de usuário não administrativo no caso de um driver de dispositivo de modo kernel ou de outro processo no sistema. A nova classe de vulnerabilidades que envolvem canais do lado de execução especulativa é relevante para muitos os limites de confiança em modelos de segurança de software existente que isolar o código e os dados em um dispositivo.

A tabela a seguir fornece um resumo dos modelos de segurança de software em que os desenvolvedores podem precisar se preocupar com essas vulnerabilidades ocorrendo:

|Limite de confiança|Descrição|
|----------------|----------------|
|Limite de máquina virtual|Aplicativos que isolar cargas de trabalho em máquinas virtuais separadas que recebem dados não confiáveis de outra máquina virtual podem estar em risco.|
|Limite de kernel|Um driver de dispositivo de modo kernel que recebe dados não confiáveis de um processo de modo de usuário não administrativo pode estar em risco.|
|Limite de processo|Um aplicativo que recebe dados não confiáveis de outro processo em execução no sistema local, como por meio de um Remote Procedure Call (RPC), memória compartilhada ou outros comunicação entre processos (IPC) mecanismos podem estar em risco.|
|Limite de enclave|Um aplicativo que é executada em um enclave seguro (por exemplo, Intel SGX) que recebe confiável para dados de fora do enclave podem estar em risco.|
|Limite de linguagem|Um aplicativo que interpreta ou just-in-(JIT) compila e executa código não confiável, escrito em uma linguagem de alto nível pode estar em risco.|

Aplicativos que têm a superfície de ataque exposto a qualquer um dos itens acima limites devem examinar o código na superfície de ataque para identificar e eliminar instâncias possíveis vulnerabilidades de canal do lado de execução especulativa de confiança. Observe que os limites de confiança expostos para superfícies de ataque remoto, como protocolos de rede remota, não foram demonstrados corre risco às vulnerabilidades de canal do lado de execução especulativa.

## <a name="potentially-vulnerable-coding-patterns"></a>Padrões de codificação vulneráveis

Vulnerabilidades de canal do lado de execução especulativa podem surgir como consequência de vários padrões de codificação. Esta seção descreve os padrões de codificação vulneráveis e fornece exemplos de cada um, mas deveria ser reconhecido que variações desses temas podem existir. Como tal, os desenvolvedores são aconselhados a levar esses padrões como exemplos e não como uma lista completa de todos os padrões de codificação vulneráveis.

Em geral, misprediction de ramificação relacionadas a condicional execução especulativa lado canais pode ocorrer quando uma expressão condicional opera em dados que pode ser controlados ou influenciados por um contexto menos confiável. Por exemplo, isso pode incluir expressões condicionais usadas em `if`, `for`, `while`, `switch`, ou instruções ternários. Para cada uma dessas instruções, o compilador pode gerar uma ramificação condicional que a CPU, em seguida, pode prever o destino de ramificação em tempo de execução.

Para cada exemplo, um comentário com a frase "ESPECULAÇÃO BARREIRA" é inserido em que um desenvolvedor poderia introduzir uma barreira como uma mitigação. Isso é discutido mais detalhadamente na seção sobre atenuações.

### <a name="speculative-out-of-bounds-load"></a>Carregar especulativo fora dos limites

Esta categoria de padrões de codificação envolve um misprediction ramificação condicional que leva a um especulativo fora dos limites acesso à memória.

#### <a name="array-out-of-bounds-load-feeding-a-load"></a>Alimentação de uma carga de carga de matriz fora dos limites

Esse padrão de codificação é o padrão de codificação vulnerável originalmente descrito para CVE-2017-5753 (ignorar verificar limites). A seção de plano de fundo deste artigo explica esse padrão em detalhes.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        // SPECULATION BARRIER
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

Da mesma forma, uma matriz fora dos limites a carga pode ocorrer em conjunto com um loop que excede seu encerramento condição devido a um misprediction. Neste exemplo, a ramificação condicional associada a `x < buffer_size` expressão pode mispredict e forma especulativa executar o corpo do `for` loop quando `x` é maior que ou igual a `buffer_size`, portanto, resultando em um especulativo carregar fora dos limites.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadBytes(unsigned char *buffer, unsigned int buffer_size) {
    for (unsigned int x = 0; x < buffer_size; x++) {
        // SPECULATION BARRIER
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

#### <a name="array-out-of-bounds-load-feeding-an-indirect-branch"></a>Matriz fora dos limites de carga alimenta um branch indireto

Esse padrão de codificação envolve o caso em que um misprediction ramificação condicional pode levar a um fora dos limites acesso a uma matriz de ponteiros de função que, em seguida, leva a uma ramificação indireta para o destino endereço que foi lido fora dos limites. O trecho a seguir fornece um exemplo que demonstra isso. 

Neste exemplo, um identificador de mensagem não confiáveis é fornecido para DispatchMessage por meio de `untrusted_message_id` parâmetro. Se `untrusted_message_id` é menor que `MAX_MESSAGE_ID`, em seguida, ele é usado para indexar uma matriz de ponteiros de função e ramificar para o destino de ramificação correspondente. Esse código é seguro em termos de arquitetura, mas se a CPU previsões incorretas de branch condicional, isso poderia resultar em `DispatchTable` que está sendo indexada por `untrusted_message_id` quando seu valor é maior que ou igual a `MAX_MESSAGE_ID`, portanto, à esquerda para um acesso fora dos limites. Isso pode resultar em execução especulativa de um endereço de destino de ramificação é derivado além dos limites da matriz que pode levar a divulgação de informações dependendo do código que é executado de forma especulativa.

```cpp
#define MAX_MESSAGE_ID 16

typedef void (*MESSAGE_ROUTINE)(unsigned char *buffer, unsigned int buffer_size);

const MESSAGE_ROUTINE DispatchTable[MAX_MESSAGE_ID];

void DispatchMessage(unsigned int untrusted_message_id, unsigned char *buffer, unsigned int buffer_size) {
    if (untrusted_message_id < MAX_MESSAGE_ID) {
        // SPECULATION BARRIER
        DispatchTable[untrusted_message_id](buffer, buffer_size);
    }
}
```

Como no caso de uma matriz fora dos limites de carga alimentar outra carga, essa condição também pode surgir em conjunto com um loop que excede sua condição de terminação devido a um misprediction.

### <a name="speculative-type-confusion"></a>Confusão tipo especulativo

Esta categoria de padrões de codificação envolve misprediction uma ramificação condicional que leva a uma confusão tipo especulativo. Os padrões de codificação nesta seção fará referência ao código de exemplo abaixo.

```cpp
enum TypeName {
    Type1,
    Type2
};

class CBaseType {
public:
    CBaseType(TypeName type) : type(type) {}
    TypeName type;
};

class CType1 : public CBaseType {
public:
    CType1() : CBaseType(Type1) {}
    char field1[256];
    unsigned char field2;
};

class CType2 : public CBaseType {
public:
    CType2() : CBaseType(Type2) {}
    void (*dispatch_routine)();
    unsigned char field2;
};

// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ProcessType(CBaseType *obj)
{
    if (obj->type == Type1) {
        // SPECULATION BARRIER
        CType1 *obj1 = static_cast<CType1 *>(obj);

        unsigned char value = obj1->field2;

        return shared_buffer[value * 4096];
    }
    else if (obj->type == Type2) {
        // SPECULATION BARRIER
        CType2 *obj2 = static_cast<CType2 *>(obj);

        obj2->dispatch_routine();

        return obj2->field2;
    }
}
```

#### <a name="speculative-type-confusion-leading-to-an-out-of-bounds-load"></a>Confusão tipo especulativo levando a uma carga fora dos limites

Esse padrão de codificação envolve o caso em que uma confusão tipo especulativo pode resultar em um fora dos limites ou acesso confundido por tipo de campo em que o valor carregado feeds de um endereço de carregamento subsequente. Isso é semelhante ao padrão de codificação fora dos limites de matriz, mas manifestado por meio de uma alternativa a sequência de codificação, como mostrado acima. Neste exemplo, um ataque contexto pode fazer com que o contexto da vítima para executar `ProcessType` várias vezes com um objeto do tipo `CType1` (`type` campo é igual a `Type1`). Isso terá o efeito de treinamento a ramificação condicional para o primeiro `if` instrução não prever obtido. O contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` com um objeto do tipo `CType2`. Isso pode resultar em uma confusão tipo especulativo se ramificar a condicional para o primeiro `if` instrução previsões incorretas e executa o corpo do `if` instrução, portanto, a conversão de um objeto do tipo `CType2` para `CType1`. Como `CType2` é menor do que `CType1`, o acesso de memória para `CType1::field2` resultará em um especulativo fora dos limites carregará de dados que podem ser segredos. Esse valor é usado em uma carga de `shard_buffer` que pode criar um efeito colateral observável, assim como acontece com a matriz fora dos limites exemplo descrito anteriormente.

#### <a name="speculative-type-confusion-leading-to-an-indirect-branch"></a>Confusão tipo especulativo levando a uma ramificação indireta

Essa codificação padrões envolve o caso em que uma confusão tipo especulativo pode resultar em uma ramificação indireta unsafe durante a execução especulativa. Neste exemplo, um ataque contexto pode fazer com que o contexto da vítima para executar `ProcessType` várias vezes com um objeto do tipo `CType2` (`type` campo é igual a `Type2`). Isso terá o efeito de treinamento a ramificação condicional para o primeiro `if` instrução a ser executada e o `else if` instrução, a não ser executada. O contexto de ataque pode fazer com que o contexto da vítima para executar `ProcessType` com um objeto do tipo `CType1`. Isso pode resultar em uma confusão tipo especulativo se ramificar a condicional para o primeiro `if` prevê a instrução executada e o `else if` assim prevê a instrução não é feito, executando o corpo do `else if` e conversão de um objeto do tipo `CType1` para `CType2`. Como o `CType2::dispatch_routine` campo se sobrepõe a `char` matriz `CType1::field1`, isso pode resultar em uma ramificação indireta especulativa com um destino de ramificação não intencionais. Se o contexto de ataque pode controlar os valores de byte no `CType1::field1` matriz, podem ser capaz de controlar o endereço de destino de ramificação.

## <a name="mitigation-options"></a>Opções de atenuação

Vulnerabilidades de canal do lado de execução especulativa podem ser minimizadas ao fazer alterações no código-fonte. Essas alterações podem envolver a redução de instâncias específicas de uma vulnerabilidade, como adicionando uma *barreira especulação*, ou fazendo alterações no design de um aplicativo para tornar as informações confidenciais inacessível para especulativo execução.

### <a name="speculation-barrier-via-manual-instrumentation"></a>Barreira especulação via instrumentação manual

Um *barreira especulação* podem ser inseridos manualmente por um desenvolvedor para impedir a execução continue em um caminho não arquitetura especulativa. Por exemplo, um desenvolvedor pode inserir uma barreira especulação antes de um padrão de codificação perigosa no corpo de um bloco condicional, no início do bloco (após a ramificação condicional) ou antes da primeira carga for um problema. Isso impedirá um misprediction ramificação condicional da execução do código perigoso em um caminho não arquitetura serializando a execução. A sequência de barreira especulação difere pela arquitetura de hardware, conforme descrito pela tabela a seguir:

|Arquitetura|Barreira especulação|
|----------------|----------------|
|x86/x64|_mm_lfence()|
|ARM|não disponível no momento|
|ARM64|não disponível no momento|


Por exemplo, o padrão de código a seguir pode ser reduzido usando o `_mm_lfence` intrínseco conforme mostrado abaixo.

```cpp
// A pointer to a shared memory region of size 1MB (256 * 4096)
unsigned char *shared_buffer;

unsigned char ReadByte(unsigned char *buffer, unsigned int buffer_size, unsigned int untrusted_index) {
    if (untrusted_index < buffer_size) {
        _mm_lfence();
        unsigned char value = buffer[untrusted_index];
        return shared_buffer[value * 4096];
    }
}
```

### <a name="speculation-barrier-via-compiler-time-instrumentation"></a>Barreira especulação por meio da instrumentação de tempo do compilador

O compilador do Visual C++ no Visual Studio de 2017 (começando com a versão 15.5.5) inclui suporte para o `/Qspectre` switch que inserirá automaticamente uma barreira especulação para um conjunto limitado de padrões de codificação vulneráveis relacionadas ao CVE-2017-5753. A documentação para o [/Qspectre](https://docs.microsoft.com/en-us/cpp/build/reference/qspectre) sinalizador fornece mais informações sobre seus efeitos e uso. É importante observar que esse sinalizador não abrange todos os padrões de codificação vulneráveis e como tal, os desenvolvedores não devem confiar nele como uma mitigação abrangente para esta classe de vulnerabilidades.

### <a name="removing-sensitive-information-from-memory"></a>Remover informações confidenciais da memória

Outra técnica que pode ser usada para atenuar vulnerabilidades de canal do lado de execução especulativa é remover informações confidenciais da memória. Os desenvolvedores de software podem procurar oportunidades para refatorar o seu aplicativo, de modo que as informações confidenciais não estão acessíveis durante a execução especulativa. Isso pode ser feito pela refatoração o design de um aplicativo para isolar as informações confidenciais em processos separados. Por exemplo, um aplicativo de navegador da web pode tentar isolar os dados associados a cada origem web em processos separados, impedindo que um processo de ser capaz de acessar dados entre origens por meio da execução especulativa.

## <a name="see-also"></a>Consulte também

[Orientações para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002)

[Redução de vulnerabilidades de hardware execução especulativa lado canal](https://blogs.technet.microsoft.com/srd/2018/03/15/mitigating-speculative-execution-side-channel-hardware-vulnerabilities/)
