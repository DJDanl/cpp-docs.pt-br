---
title: Objeto de tempo de vida e gerenciamento de recursos (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8aa0e1a1-e04d-46b1-acca-1d548490700f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 365f9196f3d482098c29bf4b04610120ecbbeec4
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406036"
---
# <a name="object-lifetime-and-resource-management-modern-c"></a>Vida útil do objeto e gerenciamento de recursos (C++ moderno)
Ao contrário de linguagens gerenciadas, C++ não tem a coleta de lixo (GC), que libera automaticamente os recursos de memória não-mais-usado como um programa é executado. No C++, o gerenciamento de recursos está diretamente relacionado ao tempo de vida do objeto. Este documento descreve os fatores que afetam o tempo de vida do objeto em C++ e como gerenciá-lo.  
  
 C++ não tem o GC, principalmente porque ele não lidar com recursos sem memória. Somente os destruidores determinísticos, como aqueles em C++ podem lidar com recursos de memória e memória não igualmente. GC também tem outros problemas, como a maior sobrecarga na memória e consumo de CPU e localidade. Mas universality é um problema fundamental que não pode ser atenuado por meio de otimizações inteligentes.  
  
## <a name="concepts"></a>Conceitos  
 Uma coisa importante no gerenciamento de tempo de vida do objeto é o encapsulamento — quem está usando um objeto não precisa saber o que possui recursos que o objeto, ou como eliminá-los ou até mesmo se ele possui todos os recursos em todos os. Ele tem apenas destruir o objeto. A linguagem do C++ core foi projetada para garantir que os objetos são destruídos no horário correto, ou seja, como blocos são encerrados, na ordem inversa da construção. Quando um objeto é destruído, suas bases e membros são destruídos em uma ordem específica.  A linguagem automaticamente destrói os objetos, a menos que você faça coisas especiais, como alocação de heap ou new de posicionamento.  Por exemplo, [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md) , como `unique_ptr` e `shared_ptr`, e, como contêineres da biblioteca padrão C++ `vector`, encapsular **novo** /  **Exclua** e `new[]` / `delete[]` em objetos, que têm destruidores. É por isso que ele é tão importante usar ponteiros inteligentes e contêineres da biblioteca padrão C++.  
  
 Outro conceito importante no gerenciamento de tempo de vida: destruidores. Os destruidores encapsulam a versão do recurso.  (O mnemônico comumente usado é RRID, o recurso de versão é destruição).  Um recurso é algo que você obtenha do "sistema" e tem que dar novamente mais tarde.  Memória é o recurso mais comuns, mas também há arquivos, soquetes, texturas e outros recursos sem memória. Um recurso de "proprietário" significa que você pode usá-lo quando necessário, mas você também precisará liberá-lo quando tiver terminado com ele.  Quando um objeto é destruído, seu destruidor libera os recursos que ele pertence.  
  
 O conceito de final é o DAG (grafo acíclico direcionado).  A estrutura de propriedade em um programa de forma um DAG. Nenhum objeto pode ter em si — que não só é impossível, mas também inerentemente sem sentido. Mas os dois objetos podem compartilhar a propriedade de um terceiro objeto.  Vários tipos de links são possíveis em um DAG como este: A é membro do B (B possui um), C armazena um `vector<D>` (C possui cada elemento D), E armazena um `shared_ptr<F>` (E compartilha a propriedade de F, possivelmente com outros objetos), e assim por diante.  Contanto que não há nenhum ciclo e cada link no DAG é representado por um objeto que tem um destruidor (em vez de um ponteiro bruto, identificadores ou outro mecanismo), em seguida, perda de recursos é impossível porque o idioma impede que eles. Recursos são liberados imediatamente depois que eles não forem mais necessários, sem um coletor de lixo em execução. O tempo de vida de controle é livre de sobrecarga para o escopo de pilha, bases, membros e casos relacionados e baixo custo para `shared_ptr`.  
  
### <a name="heap-based-lifetime"></a>Tempo de vida de heap  
 Tempo de vida do objeto de heap, use [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md). Use `shared_ptr` e `make_shared` como o ponteiro padrão e do alocador. Use `weak_ptr` para quebra de ciclos, faça o cache e observe objetos sem afetar ou supondo que nada sobre seus tempos de vida.  
  
```cpp  
void func() {  
  
auto p = make_shared<widget>(); // no leak, and exception safe  
...  
p->draw();   
  
} // no delete required, out-of-scope triggers smart pointer destructor  
```  
  
 Use `unique_ptr` para a propriedade exclusiva, por exemplo, no *pimpl* linguagem. (Consulte [Pimpl para encapsulamento do tempo de compilação](../cpp/pimpl-for-compile-time-encapsulation-modern-cpp.md).) Fazer uma `unique_ptr` o principal alvo dos explícitos **nova** expressões.  
  
```cpp  
unique_ptr<widget> p(new widget());  
```  
  
 Você pode usar ponteiros brutos para a ausência de propriedade e de observação. Um ponteiro de proprietário não pode ser dangle, mas ele não pode deixar vazar.  
  
```cpp  
class node {  
  ...  
  vector<unique_ptr<node>> children; // node owns children  
  node* parent; // node observes parent, which is not a concern  
  ...  
};  
node::node() : parent(...) { children.emplace_back(new node(...) ); }  
```  
  
 Quando a otimização de desempenho for necessária, você talvez precise usar *bem encapsulado* possui ponteiros e chamadas explícitas para excluir. Um exemplo é quando você implementa sua própria estrutura de dados de nível baixo.  
  
### <a name="stack-based-lifetime"></a>Tempo de vida de pilha  
 No C++ moderno, *escopo baseado em pilha* é uma maneira eficiente para escrever um código robusto, porque ele combina automático *tempo de vida de pilha* e *tempo de vida de membro de dados* com alta eficiência — tempo de vida de controle é essencialmente gratuito de sobrecarga. Tempo de vida de objeto de heap requer gerenciamento manual atentas e pode ser a origem de perda de recursos e as ineficiências, especialmente quando você estiver trabalhando com ponteiros brutos. Considere este código, que demonstra o escopo baseado em pilha:  
  
```cpp  
class widget {  
private:  
    gadget g;   // lifetime automatically tied to enclosing object  
public:  
    void draw();  
};  
  
void functionUsingWidget () {  
    widget w;   // lifetime automatically tied to enclosing scope  
                // constructs w, including the w.g gadget member  
    // ...
    w.draw();  
    // ...
} // automatic destruction and deallocation for w and w.g  
  // automatic exception safety,   
  // as if "finally { w.dispose(); w.g.dispose(); }"  
```  
  
 Use o tempo de vida estático com moderação (estático global, estática de local de função) porque problemas podem surgir. O que acontece quando o construtor de um objeto global gera uma exceção? Normalmente, as falhas de aplicativo de forma que pode ser difícil de depurar. Ordem de construção é problemático para objetos de tempo de vida estático e não é seguro em simultaneidade. Não só é a construção de objeto um problema, ordem de destruição pode ser complexo, especialmente onde o polimorfismo estiver envolvido. Mesmo que seu objeto ou uma variável não é polimórfico e não tem a construção/destruição complexa de ordenação, ainda há o problema de simultaneidade de thread-safe. Um aplicativo multi-threaded com segurança não é possível modificar os dados em objetos estáticos sem a necessidade de armazenamento local de thread, bloqueios de recursos e outras precauções especiais.  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)